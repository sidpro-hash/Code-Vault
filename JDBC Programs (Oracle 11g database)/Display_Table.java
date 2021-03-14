import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.ResultSetMetaData;

import java.util.Scanner;


class Display_Table{
	public static void main(String []args){
		String url = "jdbc:oracle:thin:@localhost:1521:XE";
		String uname = "admin";
		String pass = "admin";
		
		if(args.length==0){
			System.out.println("Usages: java Display_Table TableName");
			System.exit(1);
		}
		String query = "SELECT * FROM "+args[0];
		try {
            Class.forName("oracle.jdbc.driver.OracleDriver");
        }
		catch(Exception e) {
			e.printStackTrace();
		} 
		
		try(Scanner scan = new Scanner(System.in);
			Connection con = DriverManager.getConnection(url,uname,pass);){
			
			Statement stmt1 = con.createStatement();
			ResultSet rs = stmt1.executeQuery(query);
			ResultSetMetaData rsmd = rs.getMetaData();
			//System.out.println("Total columns:"+rsmd.getColumnCount());
			//System.out.println("Column Name of 1st column:"+rsmd.getColumnName(1));
			//System.out.println("Column Type Name of 1st column:"+rsmd.getColumnTypeName(1));
			int count = rsmd.getColumnCount();
			while(rs.next()){
					for(int i=0;i<count;++i)
						System.out.print(rs.getString(i+1)+" ");
					
					System.out.println();
			}
		
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