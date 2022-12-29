/* wolfSSL-TLS-PSK-Client.cs
 *
 * Copyright (C) 2006-2022 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */





using System;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;
using System.IO;
using System.Net;
using System.Net.Sockets;
using wolfSSL.CSharp;



public class wolfSSL_TLS_PSK_Client
{


    /// <summary>
    /// Example of a PSK function call back
    /// </summary>
    /// <param name="ssl">pointer to ssl structure</param>
    /// <param name="hint">hint if any from connecting</param>
    /// <param name="identity">identity to send to server</param>
    /// <param name="id_max">max length of identity</param>
    /// <param name="key">buffer to hold key</param>
    /// <param name="max_key">max key size</param>
    /// <returns>size of key set</returns>
    public static uint my_psk_client_cb(IntPtr ssl, string hint, IntPtr identity, uint id_max, IntPtr key, uint max_key)
    {
        /* C# client */
        byte[] id = { 67, 35, 32, 99, 108, 105, 101, 110, 116 };
        if (id_max < 9)
            return 0;
        Marshal.Copy(id, 0, identity, 9);

        /* Use desired key, note must be a key smaller than max key size parameter 
            Replace this with desired key. Is trivial one for testing */
        if (max_key < 4)
            return 0;
        byte[] tmp = { 26, 43, 60, 77 };
        Marshal.Copy(tmp, 0, key, 4);

        return (uint)4;
    }


    private static void clean(IntPtr ssl, IntPtr ctx)
    {
        wolfssl.free(ssl);
        wolfssl.CTX_free(ctx);
        wolfssl.Cleanup();
    }


    public static void Main(string[] args)
    {
        IntPtr ctx;
        IntPtr ssl;
        Socket tcp;

        wolfssl.psk_client_delegate psk_cb = new wolfssl.psk_client_delegate(my_psk_client_cb);

        StringBuilder dhparam = new StringBuilder("dh2048.pem");

        StringBuilder buff = new StringBuilder(1024);
        StringBuilder reply = new StringBuilder("Hello, this is the wolfSSL C# client psk wrapper");

        wolfssl.Init();

        Console.WriteLine("Calling ctx Init from wolfSSL");
        ctx = wolfssl.CTX_new(wolfssl.usev23_client());
        if (ctx == IntPtr.Zero)
        {
            Console.WriteLine("Error creating ctx structure");
            return;
        }
        Console.WriteLine("Finished init of ctx .... now load in cert and key");

        StringBuilder ciphers = new StringBuilder(new String(' ', 4096));
        wolfssl.get_ciphers(ciphers, 4096);
        Console.WriteLine("Ciphers : " + ciphers.ToString());

        short minDhKey = 128;
        wolfssl.CTX_SetMinDhKey_Sz(ctx, minDhKey);
        Console.Write("Setting cipher suite to ");

        /* In order to use static PSK build wolfSSL with the preprocessor flag WOLFSSL_STATIC_PSK */
        StringBuilder set_cipher = new StringBuilder("DHE-PSK-AES128-CBC-SHA256");
        Console.WriteLine(set_cipher);
        if (wolfssl.CTX_set_cipher_list(ctx, set_cipher) != wolfssl.SUCCESS)
        {
            Console.WriteLine("Failed to set cipher suite");
            return;
        }

        /* Test psk use with DHE */
        wolfssl.CTX_set_psk_client_callback(ctx, psk_cb);

        /* set up TCP socket */
        tcp = new Socket(AddressFamily.InterNetwork, SocketType.Stream,
                              ProtocolType.Tcp);
        try
        {
            tcp.Connect("localhost", 11111);
        }
        catch (Exception e)
        {
            Console.WriteLine("tcp.Connect() error " + e.ToString());
            wolfssl.CTX_free(ctx);
            return;
        }
        if (!tcp.Connected)
        {
            Console.WriteLine("tcp.Connect() failed!");
            tcp.Close();
            wolfssl.CTX_free(ctx);
            return;
        }

        Console.WriteLine("Connected TCP");
        ssl = wolfssl.new_ssl(ctx);
        if (ssl == IntPtr.Zero)
        {
            Console.WriteLine("Error in creating ssl object");
            wolfssl.CTX_free(ctx);
            return;
        }

        if (wolfssl.set_fd(ssl, tcp) != wolfssl.SUCCESS)
        {
            /* get and print out the error */
            Console.WriteLine(wolfssl.get_error(ssl));
            tcp.Close();
            clean(ssl, ctx);
            return;
        }

        wolfssl.SetTmpDH_file(ssl, dhparam, wolfssl.SSL_FILETYPE_PEM);

        if (wolfssl.connect(ssl) != wolfssl.SUCCESS)
        {
            /* get and print out the error */
            Console.WriteLine(wolfssl.get_error(ssl));
            tcp.Close();
            clean(ssl, ctx);
            return;
        }

        /* print out results of TLS/SSL accept */
        Console.WriteLine("SSL version is " + wolfssl.get_version(ssl));
        Console.WriteLine("SSL cipher suite is " + wolfssl.get_current_cipher(ssl));


        if (wolfssl.write(ssl, reply, reply.Length) != reply.Length)
        {
            Console.WriteLine("Error in write");
            tcp.Close();
            clean(ssl, ctx);
            return;
        }

        /* read and print out the message then reply */
        if (wolfssl.read(ssl, buff, 1023) < 0)
        {
            Console.WriteLine("Error in read");
            tcp.Close();
            clean(ssl, ctx);
            return;
        }
        Console.WriteLine(buff);

        wolfssl.shutdown(ssl);
        tcp.Close();
        clean(ssl, ctx);
    }
}
