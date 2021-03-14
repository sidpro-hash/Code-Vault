//SET PATH=F:\SOFT\JDK 7\bin
import java.sql.*;
public class Demo1 {
      public static void main(String[] args) {
          try{
          	   // Load and register the driver
          	   try {
          			Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
          	   }
          	   catch(Exception e) {
          	       e.printStackTrace();
          	   }
          		//Driver myDriver = new sun.jdbc.odbc.JdbcOdbcDriver();
          		//DriverManager.registerDriver(myDriver);

          		// Establish the connection to the database server
          		// urlstring,enter workspace username or SYSTEM,password
          		Connection cn = DriverManager.getConnection("jdbc:odbc:CollegeekDSN","admin","admin");

          		// Create a statement
          		Statement st = cn.createStatement();

          		// Execute the statement
          		ResultSet rs = st.executeQuery("select * from Student");
          	  // Retrieve the results
          		while(rs.next())
          			System.out.println(rs.getString(1)+" "+rs.getString(2));

          		// Close the statement and connection
          		st.close();
          		cn.close();
            }
            catch(SQLException e) {
          		System.out.println(e.getMessage());
            }

        }
    }
