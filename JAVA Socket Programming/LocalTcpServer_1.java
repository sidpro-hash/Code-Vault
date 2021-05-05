import java.io.*;
import java.net.*;
import java.util.Scanner;
public class LocalTcpServer_1{
	public static void main(String[] args){
		try(Scanner scan = new Scanner(System.in)){
			/*
			* Two Classes are being used: Socket and ServerSocket
			* Socket and ServerSocket classes are used for connection-oriented socket programming.
			* The Socket class is used to communicate client and server. 
			* Through this class, we can read and write message.
			* The ServerSocket class is used at server-side.
			*/
			
			//To create the server application pass the port number
			ServerSocket server = new ServerSocket(6969);
			
			/*
			* The accept() method of ServerSocket class blocks the console 
			* until the client is connected. After the successful connection 
			* of client, it returns the instance of Socket at server-side.
			*/
			//  Listens for a connection to be made to this socket and accepts it.
			Socket socket = server.accept();
			
			//returns the InputStream attached with this socket.
			DataInputStream in = new DataInputStream(socket.getInputStream());
			
			//returns the OutputStream attached with this socket.
			DataOutputStream out = new DataOutputStream(socket.getOutputStream());
			
			String from_client,to_client;
			while(true){
				from_client = (String)in.readUTF(); //  read a string that has been encoded using the UTF-8 format.
				System.out.printf("Client: %s\n",from_client);
				if(from_client.toLowerCase().equals("bye"))break;
				System.out.print("Server: ");
				to_client = scan.nextLine();
				out.writeUTF(to_client); // write a string to the output stream using UTF-8 encoding in portable manner.
				if(to_client.toLowerCase().equals("bye"))break;
			}
			server.close();
		} catch(Exception e){System.out.println(e);}
	}
}