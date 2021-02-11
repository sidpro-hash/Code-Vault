import java.util.Scanner;
import java.io.IOException;
import java.net.*;

class Udp_server{
	public static void main(String []args){
		try(Scanner scan = new Scanner(System.in)){
		
		/*
		* DatagramSocket and DatagramPacket classes are used for connection-less socket programming.
		* A datagram socket is the sending or receiving point for a packet delivery service. Each packet 
		* sent or received on a datagram socket is individually addressed and routed. Multiple packets 
		* sent from one machine to another may be routed differently, and may arrive in any order. 
		*/
		// creates a datagram socket and binds it with the given Port Number.
		DatagramSocket datagram_socket = new DatagramSocket(6969);
		
		// Returns the local port to which this socket is bound.
		System.out.println("Server Listens on remote port: " + datagram_socket.getLocalPort());
		byte[] buffer = new byte[1024];
		while(true){
			
			/*
			* Datagram packets are used to implement a connectionless packet delivery service.
			* Each message is routed from one machine to another based solely on information 
			* contained within that packet. Multiple packets sent from one machine to another 
			* might be routed differently, and might arrive in any order. Packet delivery is not guaranteed.
			*/
			// Constructs a DatagramPacket for receiving packets of given length.
			DatagramPacket receive_datagram = new DatagramPacket(buffer,buffer.length);
			
			// Receives a datagram packet from this socket.
			datagram_socket.receive(receive_datagram);
			
			// Returns the address to which this socket is connected.
			InetAddress ip = receive_datagram.getAddress();
			
			// The getData() method of Java DatagramPacket class returns the data buffer.
			// Any data that is to be received or is to be sent, firstly starts from the
			// offset(starting index, by default 0) in the buffer and then runs for length long. 
			String input = new String(receive_datagram.getData());	
			
			System.out.println("Client: "+input.trim());
			if(input.trim().toLowerCase().equals("bye"))break;
			System.out.print("Server: ");
			input = scan.nextLine();
			// Clear the buffer after every message.
			buffer = new byte[1024];
			buffer = input.getBytes();
			
			// Constructs a datagram packet for sending packets of given length to the specified port number on the specified host.
			DatagramPacket send_datagram = new DatagramPacket(buffer,buffer.length,ip,receive_datagram.getPort());
			
			// Sends a datagram packet from this socket
			datagram_socket.send(send_datagram);
			
			buffer = new byte[1024];
			if(input.toLowerCase().equals("bye"))break;
		}
			
		}catch(IOException e){
			e.printStackTrace();
		}catch(Exception e){
			e.printStackTrace();
		}
	}
}