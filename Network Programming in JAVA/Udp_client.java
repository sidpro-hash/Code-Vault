import java.util.Scanner;
import java.io.IOException;
import java.net.*;

class Udp_client{
	public static void main(String []args){
		try(Scanner scan = new Scanner(System.in)){
		
		/*
		* DatagramSocket and DatagramPacket classes are used for connection-less socket programming.
		* A datagram socket is the sending or receiving point for a packet delivery service. Each packet 
		* sent or received on a datagram socket is individually addressed and routed. Multiple packets 
		* sent from one machine to another may be routed differently, and may arrive in any order. 
		*/
		// creates a datagram socket and binds it with the available Port Number on the localhost machine.
		DatagramSocket datagram_socket = new DatagramSocket();
		
		// Gets the local address to which the socket is bound.
		InetAddress ip = InetAddress.getLocalHost();
		byte buffer[] = null;
		// Returns the local port to which this socket is bound.
		System.out.println("Client started on local port: " + datagram_socket.getLocalPort());
		
		while(true){
			System.out.print("Client: ");
			String input = scan.nextLine();
			buffer = input.getBytes();
			
			/*
			* Datagram packets are used to implement a connectionless packet delivery service.
			* Each message is routed from one machine to another based solely on information 
			* contained within that packet. Multiple packets sent from one machine to another 
			* might be routed differently, and might arrive in any order. Packet delivery is not guaranteed.
			*/
			// Constructs a datagram packet for sending packets of length length to the specified port number on the specified host.
			DatagramPacket send_datagram = new DatagramPacket(buffer,buffer.length,ip,6969);
			
			// Sends a datagram packet from this socket
			datagram_socket.send(send_datagram);
			if(input.toLowerCase().equals("bye"))break;
			
			// Clear the buffer after every message.
			buffer = new byte[1024];
			
			//Constructs a DatagramPacket for receiving packets of given length.
			DatagramPacket receive_datagram = new DatagramPacket(buffer,buffer.length);
			
			// Receives a datagram packet from this socket.
			datagram_socket.receive(receive_datagram);
			
			// The getData() method of Java DatagramPacket class returns the data buffer.
			// Any data that is to be received or is to be sent, firstly starts from the
			// offset(starting index, by default 0) in the buffer and then runs for length long.
			input = new String(receive_datagram.getData());

			System.out.println("Server: "+input.trim());
			if(input.trim().toLowerCase().equals("bye"))break;
		}
			
		}catch(IOException e){
			e.printStackTrace();
		}catch(Exception e){
			e.printStackTrace();
		}
	}
}