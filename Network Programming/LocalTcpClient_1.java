import java.io.*;
import java.net.*;
import java.util.Scanner;

public class LocalTcpClient_1{
	public static void main(String[] args){
	try(Scanner scan = new Scanner(System.in)){
		
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
		
		String from_server,to_server;
		while(true){
			System.out.print("Client: ");
			to_server = scan.nextLine();
			out.writeUTF(to_server); // write a string to the output stream using UTF-8 encoding in portable manner.
			if(to_server.toLowerCase().equals("bye"))break;
			from_server = in.readUTF(); //  read a string that has been encoded using the UTF-8 format.
			System.out.printf("Server: %s\n",from_server);		
			if(from_server.toLowerCase().equals("bye"))break;
		}
		socket.close();	
	
	    }catch(Exception e){System.out.println(e);}
	}
}