import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

import java.util.Scanner;


class Student_Reg{
	public static void main(String []args){
		String url = "jdbc:oracle:thin:@localhost:1521:XE";
		String uname = "admin";
		String pass = "admin";
		String query = "SELECT * FROM Student";
		
		try {
            Class.forName("oracle.jdbc.driver.OracleDriver");
        }
		catch(Exception e) {
			e.printStackTrace();
		} 
		
		try(Scanner scan = new Scanner(System.in);
			Connection con = DriverManager.getConnection(url,uname,pass);){
				
			System.out.println("----> STUDENT REGISTRATION <----");
			System.out.println();
			String FirstName,LastName,Gender,City;
			long EnNo;
			System.out.print("Enter FirstName: ");
			FirstName = scan.nextLine();
			System.out.print("Enter LastName: ");
			LastName = scan.nextLine();
			System.out.print("Enter Enrollment: ");
			EnNo = scan.nextLong();
			System.out.println("1 Male");
			System.out.println("2 Female");
			System.out.println("3 Other");
			System.out.print("Select Gender 1/2/3 ?: ");
			int option = scan.nextInt();
			switch(option){
				case 1:Gender="Male";break;
				case 2:Gender="Female";break;
				case 3:Gender="Other";break;
				default:
					Gender="Other";
			}
			System.out.println("1 Ahmedabad");
			System.out.println("2 Bhavnagar");
			System.out.println("3 Gandhinagar");
			System.out.println("4 Khambhat");
			System.out.println("5 Rajkot");
			System.out.println("6 Surat");
			System.out.println("7 Surendranagar");
			System.out.println("8 Valsad");
			System.out.print("Select City [1-8] ?: ");
			option = scan.nextInt();
			switch(option){
				case 1:City="Ahmedabad";break;
				case 2:City="Bhavnagar";break;
				case 3:City="Gandhinagar";break;
				case 4:City="Khambhat";break;
				case 5:City="Rajkot";break;
				case 6:City="Surat";break;
				case 7:City="Surendranagar";break;
				case 8:City="Valsad";break;
				default:
					City="Ahmedabad";
			}
			System.out.println("Your details are:");
			System.out.println(EnNo+" "+FirstName+" "+LastName+" "+Gender+" "+City);
			
			PreparedStatement stmt = con.prepareStatement("INSERT INTO Student VALUES(?,?,?,?,?)");
			stmt.setLong(1,EnNo);
			stmt.setString(2,LastName);
			stmt.setString(3,FirstName);
			stmt.setString(4,Gender);
			stmt.setString(5,City);
			int n = stmt.executeUpdate(); 
			stmt.close();
			
			System.out.println(n+" row(s) inserted.");
			
			Statement stmt1 = con.createStatement();
			ResultSet rs = stmt1.executeQuery(query);
			while(rs.next())
				System.out.println(rs.getLong("ENNO")+" "+rs.getString("LASTNAME")+" "+rs.getString(3)+" "+rs.getString(4)+" "+rs.getString(5));
			
			stmt1.close();
		}
		catch(SQLException e){
			e.printStackTrace();
		}
		catch(Exception e){
			e.printStackTrace();
		}
	}
}