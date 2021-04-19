package sidpro;  
  
import java.sql.*;
import static database.Database.*;  
  
public class Register_user {  
  
	public static int register(StudentBean u){  
		int status=0;  

				long eno = Long.valueOf(u.getEnNo());
				try {
					Class.forName(CLASSNAME);
				}catch(Exception e) {e.printStackTrace();}
				
				try(Connection con = DriverManager.getConnection(URL,UNAME,PASSWORD);){

					PreparedStatement stmt = con.prepareStatement("INSERT INTO user_jsp VALUES(?,?,?,?,?)");
					stmt.setLong(1,eno);
					stmt.setString(2,u.getLastName());
					stmt.setString(3,u.getFirstName());
					stmt.setString(4,u.getGender());
					stmt.setString(5,u.getPassword());
					int n = stmt.executeUpdate(); 
					stmt.close();
					//out.println("<p>"+n+" row(s) inserted.</p>");
					//response.sendRedirect("Display_Info");
					//System.out.println(n+" row(s) inserted.");
					
				}
				catch(SQLException e){
					
					e.printStackTrace();
				}
				catch(Exception e){
					e.printStackTrace();
					//out.println("<p>"+e+"</p>");
				} 
			  
		return status;  
	}  
  
}  