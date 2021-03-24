
import java.io.IOException;
import java.io.PrintWriter;


import javax.servlet.ServletException;
import javax.servlet.ServletContext;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.RequestDispatcher;
import java.util.regex.Pattern;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.PreparedStatement;


// First method of creating servlet
public class Client_side_validate extends HttpServlet{
	private String message;
	
	public void init() throws ServletException{
		message = "Validating Employee information";
	}
	
	public void doPost(HttpServletRequest request,HttpServletResponse response) throws ServletException,IOException{
		response.setContentType("text/html;charset=UTF-8");
			
			
		PrintWriter out = response.getWriter();
			
			//String ppath = request.getContextPath();
			String fname = (request.getParameter("fname")==null)?"":request.getParameter("fname");
			String lname = (request.getParameter("lname")==null)?"":request.getParameter("lname");
			String email = (request.getParameter("email")==null)?"":request.getParameter("email");
			String pass = (request.getParameter("pass")==null)?"":request.getParameter("pass");
			String gender = request.getParameter("gender");
			String fname_error="",lname_error="",pass_error="",email_error="";
			int years = Integer.valueOf(request.getParameter("exp"));
			boolean go = true;
		
			if(fname.equals("")){
				go=false;
				fname_error=" * First Name is Required!";
			}
			else{
				if(!Pattern.matches("^[a-zA-Z]*$",fname)){
					go=false;
					fname_error=" * Only letters and white space allowed!";
				}
			}
			if(lname.equals("")){
				go=false;
				lname_error=" * Last Name is Required! ";
			}
			else{
				if(!Pattern.matches("^[a-zA-Z]*$",lname)){
					go=false;
					lname_error=" * Only letters and white space allowed!";
				}
			}
			if(pass.equals("")){
				go=false;
				pass_error=" * Password is Required!";
			}else{
				if(pass.length()<8){
					go=false;
					pass_error=" * Password length must be 8 !";
				}
			}
			if(email.equals("")){
				go=false;
				email_error=" * Email is Required!";
			}
			else{
				Pattern ptr = Pattern.compile("^[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,6}$",Pattern.CASE_INSENSITIVE);
				if(!ptr.matcher(email).matches()){
					go=false;
					email_error=" * Invalid email format!";
				}
			}
			
			if(go){
				
				ServletContext config=getServletContext();  
				String classname =  config.getInitParameter("classname");
				String url =  config.getInitParameter("url");
				String uname = config.getInitParameter("username");
				String password = config.getInitParameter("password");

				try {
					Class.forName(classname);
				}catch(Exception e) {e.printStackTrace();}
				
				try(Connection con = DriverManager.getConnection(url,uname,password);){

					PreparedStatement stmt = con.prepareStatement("INSERT INTO Emp10 VALUES(?,?,?,?,?,?)");
					stmt.setString(1,email);
					stmt.setString(2,lname);
					stmt.setString(3,fname);
					stmt.setString(4,gender);
					stmt.setInt(5,years);
					stmt.setString(6,pass);
					int n = stmt.executeUpdate(); 
					stmt.close();
					//out.println("<p>"+n+" row(s) inserted.</p>");
				
					//System.out.println(n+" row(s) inserted.");
					
				}
				catch(SQLException e){
					
					out.println("<p>"+e+"</p>");
				}
				catch(Exception e){
					
					out.println("<p>"+e+"</p>");
				}
				
					
			}else{
				out.println("["
				+"{\"fname_error\":\""+fname_error+"\"},"
				+"{\"lname_error\":\""+lname_error+"\"},"
				+"{\"pass_error\":\""+pass_error+"\"},"
				+"{\"email_error\":\""+email_error+"\"}]");
				
			}
			
		
				
	}
	
}