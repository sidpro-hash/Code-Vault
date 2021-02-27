import java.io.*;
import java.net.*;
import java.util.Scanner;

public class LocalTcpClient{
	public static void main(String[] args){
	try{
		Scanner scan = new Scanner(System.in);
		
		/*
		* Two Classes are being used: Socket and ServerSocket
		* Socket and ServerSocket classes are used for connection-oriented socket programming.
		* The Socket class is used to communicate client and server. 
		* Through this class, we can read and write message.
		* The ServerSocket class is used at server-side.
		*/
		
		//To create the client application pass the IP address or hostname of the Server and a port number
		Socket socket = new Socket("localhost",6969);
		
		//returns the InputStream attached with this socket.
		DataInputStream in = new DataInputStream(socket.getInputStream());
		
		//returns the OutputStream attached with this socket.
		DataOutputStream out = new DataOutputStream(socket.getOutputStream());
		
		// Returns the local port to which this socket is bound.
		System.out.println("Client started on local port: " + socket.getLocalPort());
		
		// Returns the remote port to which this socket is connected.
		System.out.println("Server Listens on remote port: " + socket.getPort());
		
		System.out.print("Enter size of array: ");
		int n = scan.nextInt();
		System.out.println("Enter "+n+" array elements:");
		int[] arr = new int[n];
		for(int i=0;i<n;++i)arr[i]=scan.nextInt();
		out.writeInt(n);
		for(int i=0;i<n;++i){
			out.writeInt(arr[i]); // write an int to the output stream as bytes
		}
		System.out.print("Sorted elements: ");
		int x; 
		for(int i=0;i<n;++i){
			x = in.readInt(); // read input bytes and return an int value.
			System.out.print(x+" ");
		}
		
	    }catch(Exception e){System.out.println(e);}
	}
}