import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.PreparedStatement;
import java.sql.CallableStatement;

import java.util.Scanner;

/*

** Table **

CREATE TABLE Testemp100 (
    emp_id int PRIMARY KEY,
    emp_name varchar(255),
    job_name varchar(255),
    salary Number(15,2)
);

** Procedure **

CREATE OR REPLACE PROCEDURE incrementSalary(per IN NUMBER,row OUT NUMBER) IS
BEGIN
UPDATE Testemp100 SET salary=salary+(salary*per/100);
row:=SQL%ROWCOUNT;
END incrementSalary;

*/

class Emp_Salary{
	public static void main(String []args){
		String url = "jdbc:oracle:thin:@localhost:1521:XE";
		String uname = "admin";
		String pass = "admin";
		String query="";
		try {
            Class.forName("oracle.jdbc.driver.OracleDriver");
        }
		catch(Exception e) {
			e.printStackTrace();
		} 
		
		try(Scanner scan = new Scanner(System.in);
			Connection con = DriverManager.getConnection(url,uname,pass);){
			
			System.out.println("Incrementing Salary of Employees By % Percentage");
			System.out.println();
			System.out.print("Enter value to increment Salary (E.g. 10): ");
			int Percentage = scan.nextInt();
			System.out.println();
			
			query = "{ call incrementSalary(?,?) }";
			CallableStatement cstmt = con.prepareCall(query);
			cstmt.setInt(1,Percentage);
			cstmt.registerOutParameter(2,java.sql.Types.INTEGER);
			cstmt.execute();
			int n = cstmt.getInt(2);
			cstmt.close();
			
			
			System.out.println(n+" row(s) Updated.");
			System.out.println();
			if(Percentage > -1)System.out.println("After "+Percentage+"% increment in Salary of Employees");
			else System.out.println("After "+(Percentage*-1)+"% Decrement in Salary of Employees");
			System.out.println();
			
			query = "SELECT * FROM Testemp100";
			Statement stmt = con.createStatement();
			ResultSet rs = stmt.executeQuery(query);
			while(rs.next())
				System.out.println(rs.getInt(1)+" "+rs.getString(2)+" "+rs.getString(3)+" "+rs.getFloat(4));
			
			stmt.close();
		}
		catch(SQLException e){
			e.printStackTrace();
		}
		catch(Exception e){
			e.printStackTrace();
		}
	}
}