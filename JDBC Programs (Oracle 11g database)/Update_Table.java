import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.ResultSetMetaData;

import java.util.Scanner;

/*

** Table **

CREATE TABLE Student (
EnNo Number NOT NULL PRIMARY KEY,
LastName varchar(255),
FirstName varchar(255),
Gender varchar(15),
City varchar(255)
);

*/

class Update_Table{
	public static void main(String []args){
		String url = "jdbc:oracle:thin:@localhost:1521:XE";
		String uname = "admin";
		String pass = "admin";
		String query;
		PreparedStatement stmt;
		try {
            Class.forName("oracle.jdbc.driver.OracleDriver");
        }
		catch(Exception e) {
			e.printStackTrace();
		} 
		
		try(Scanner scan = new Scanner(System.in);
			Connection con = DriverManager.getConnection(url,uname,pass);){
			
			
			System.out.println("----> UPDATE INFORMATION <----");
			System.out.println();
			System.out.println("NOTE: Everything is Case-sensitive");
			System.out.println();
			System.out.println("what do you want to update?");
			System.out.println("1 Enrollment No");
			System.out.println("2 LastName");
			System.out.println("3 FirstName");
			System.out.println("4 Gender");
			System.out.println("5 City");
			System.out.print("Select Option [1-5] ?: ");
			String[] data=new String[5];
			long EnNo=0;
			String[] column = {"ENNO","LASTNAME","FIRSTNAME","GENDER","CITY"};
			int n=0,op,option = scan.nextInt();
			switch(option){
				case 1:
						System.out.print("Enter new Enrollment NO: ");
						EnNo = scan.nextLong();
						scan.nextLine();
						System.out.print("Enter FirstName: ");
						data[2] = scan.nextLine();
						System.out.print("Enter LastName: ");
						data[1] = scan.nextLine();
						break;
				case 2:
						scan.nextLine();
						System.out.print("Enter new LastName: ");
						data[1] = scan.nextLine();
						System.out.print("Enter Enrollment: ");
						EnNo = scan.nextLong();
						break;
				case 3:
						scan.nextLine();
						System.out.print("Enter new FirstName: ");
						data[2] = scan.nextLine();
						System.out.print("Enter Enrollment: ");
						EnNo = scan.nextLong();
						break;
				case 4:
						System.out.println("1 Male");
						System.out.println("2 Female");
						System.out.println("3 Other");
						System.out.print("Select Gender 1/2/3 ?: ");
						op = scan.nextInt();
						switch(op){
							case 1:data[3]="Male";break;
							case 2:data[3]="Female";break;
							case 3:data[3]="Other";break;
							default:
								data[3]="Other";
						}
						System.out.print("Enter Enrollment: ");
						EnNo = scan.nextLong();
						break;
				case 5:
						System.out.println("1 Ahmedabad");
						System.out.println("2 Bhavnagar");
						System.out.println("3 Gandhinagar");
						System.out.println("4 Khambhat");
						System.out.println("5 Rajkot");
						System.out.println("6 Surat");
						System.out.println("7 Surendranagar");
						System.out.println("8 Valsad");
						System.out.print("Select City [1-8] ?: ");
						op = scan.nextInt();
						switch(op){
							case 1:data[4]="Ahmedabad";break;
							case 2:data[4]="Bhavnagar";break;
							case 3:data[4]="Gandhinagar";break;
							case 4:data[4]="Khambhat";break;
							case 5:data[4]="Rajkot";break;
							case 6:data[4]="Surat";break;
							case 7:data[4]="Surendranagar";break;
							case 8:data[4]="Valsad";break;
							default:
								data[4]="Ahmedabad";
						}
						System.out.print("Enter Enrollment: ");
						EnNo = scan.nextLong();
			}
			switch(option){
				case 1:
						query = "UPDATE Student SET ENNO=? WHERE LASTNAME=? AND FIRSTNAME=?";
						stmt = con.prepareStatement(query);
						stmt.setLong(1,EnNo);
						stmt.setString(2,data[1]);
						stmt.setString(3,data[2]);
						n = stmt.executeUpdate(); 
						stmt.close();
						break;
				case 2:
				case 3:
				case 4:
				case 5:
						query = "UPDATE Student SET "+column[option-1]+"=? WHERE ENNO=?";
						stmt = con.prepareStatement(query);
						stmt.setString(1,data[option-1]);
						stmt.setLong(2,EnNo);
						n = stmt.executeUpdate(); 
						stmt.close();
						break;
			}
			System.out.println(n+" row(s) Updated.");
			if(n>0){
					query = "SELECT * FROM Student WHERE ENNO="+EnNo;
					Statement stmt1 = con.createStatement();
					ResultSet rs = stmt1.executeQuery(query);
					while(rs.next())
						System.out.println(rs.getLong("ENNO")+" "+rs.getString("LASTNAME")+" "+rs.getString(3)+" "+rs.getString(4)+" "+rs.getString(5));
			
					stmt1.close();
			}
		}
		catch(SQLException e){
			e.printStackTrace();
		}
		catch(Exception e){
			e.printStackTrace();
		}
	}
}