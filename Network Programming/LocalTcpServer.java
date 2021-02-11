import java.io.*;
import java.net.*;
import java.util.Arrays;
public class LocalTcpServer{
	public static void main(String[] args){
	try{
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
		
		int n = in.readInt(); // read input bytes and return an int value.
		System.out.println("array size "+n+" recived.");
		int[] arr = new int[n];
		for(int i=0;i<n;++i){
			arr[i] = in.readInt();
		}
		Arrays.sort(arr);
		for(int i=0;i<n;++i)out.writeInt(arr[i]); // write an int to the output stream as bytes
	} catch(Exception e){
		System.out.println(e);
		
	}
	}
}