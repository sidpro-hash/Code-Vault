import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.ResultSetMetaData;
import java.sql.DatabaseMetaData;

import java.util.Scanner;


class Table_content{
	public static void main(String []args){
		String url = "jdbc:oracle:thin:@localhost:1521:XE";
		String uname = "admin";
		String pass = "admin";
		
		if(args.length==0){
			System.out.println("Usages: java Table_content TableName");
			System.exit(1);
		}
		String query = "select * from "+args[0];
		try {
            Class.forName("oracle.jdbc.driver.OracleDriver");
        }
		catch(Exception e) {
			e.printStackTrace();
		} 
		
		try(Scanner scan = new Scanner(System.in);
			Connection con = DriverManager.getConnection(url,uname,pass);){
			//DatabaseMetaData dbms = con.getMetaData();
			
			Statement stmt1 = con.createStatement();
			ResultSet rs = stmt1.executeQuery(query);
			ResultSetMetaData rsmd = rs.getMetaData();
			System.out.println("Total columns:"+rsmd.getColumnCount());
			
			//System.out.println("Column Name of 1st column:"+rsmd.getColumnName(1));
			//System.out.println("Column Type Name of 1st column:"+rsmd.getColumnTypeName(1));
			//ResultSet rs1 = dbms.getTables(null,null,null,new String[]{"TABLE"});
			/*
			while(rs1.next())
				System.out.println(rs1.getString("TABLE_NAME")+" "+rs1.getString("REMARKS"));
			System.out.println(rsmd.getTableName(1));*/
			
			int count = rsmd.getColumnCount();
			System.out.println("Table       Column      Data Type  Length  Nullable");
			
			System.out.printf("%-12s %-12s %-10s %-5d %6s",args[0].toUpperCase(),rsmd.getColumnName(1),rsmd.getColumnTypeName(1),rsmd.getColumnDisplaySize(1),(rsmd.isNullable(1)==0)?"false":"true");
			
			System.out.println();
			for(int i=1;i<count;++i){
				System.out.printf("%-12s %-12s %-10s %-5d %6s","",rsmd.getColumnName(i+1),rsmd.getColumnTypeName(i+1),rsmd.getColumnDisplaySize(i+1),(rsmd.isNullable(i+1)==0)?"false":"true");
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