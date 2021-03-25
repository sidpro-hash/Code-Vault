
import java.io.IOException;
import java.io.PrintWriter;


import javax.servlet.ServletException;
import javax.servlet.ServletConfig;
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
public class Validation_Info extends HttpServlet{
	private String message;
	
	public void init() throws ServletException{
		message = "Validating Employee information";
	}
	
	public void doPost(HttpServletRequest request,HttpServletResponse response) throws ServletException,IOException{
		response.setContentType("text/html");
		PrintWriter out = response.getWriter();
		//String ppath = request.getContextPath();
		String fname = ((request.getParameter("fname")!=null)?request.getParameter("fname"):"");
		String lname = (request.getParameter("lname")==null)?"":request.getParameter("lname");
		String email = (request.getParameter("email")==null)?"":request.getParameter("email");
		String pass = (request.getParameter("pass")==null)?"":request.getParameter("pass");
		String gender = request.getParameter("gender");
		int years = Integer.valueOf(request.getParameter("exp"));
		boolean go = true;
		
			if(fname.equals("")){
				go=false;
				request.setAttribute("fname_error", "<span style=\"color:red;\"> * First Name is Required!</span>");
			}
			else{
				if(!Pattern.matches("^[a-zA-Z]*$",fname)){
					go=false;
					request.setAttribute("fname_error", "<span style=\"color:red;\"> * Only letters and white space allowed!</span>");
				}
			}
			if(lname.equals("")){
				go=false;
				request.setAttribute("lname_error", "<span style=\"color:red;\"> * Last Name is Required!</span>");
			}
			else{
				if(!Pattern.matches("^[a-zA-Z]*$",lname)){
					go=false;
					request.setAttribute("lname_error", "<span style=\"color:red;\"> * Only letters and white space allowed!</span>");
				}
			}
			if(pass.equals("")){
				go=false;
				request.setAttribute("pass_error", "<span style=\"color:red;\"> * Password is Required!</span>");
			}else{
				if(pass.length()<8){
					go=false;
					request.setAttribute("pass_error", "<span style=\"color:red;\"> * Password length must be 8 !</span>");
				}
			}
			if(email.equals("")){
				go=false;
				request.setAttribute("email_error", "<span style=\"color:red;\"> * Email is Required!</span>");
			}
			else{
				Pattern ptr = Pattern.compile("^[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,6}$",Pattern.CASE_INSENSITIVE);
				if(!ptr.matcher(email).matches()){
					go=false;
					request.setAttribute("email_error", "<span style=\"color:red;\"> * Invalid email format!</span>");
				}
			}
			
			if(go){
				
				ServletConfig config=getServletConfig();  
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
					response.sendRedirect("Login");
					//System.out.println(n+" row(s) inserted.");
					
				}
				catch(SQLException e){
					
					out.println("<p>"+e+"</p>");
				}
				catch(Exception e){
					
					out.println("<p>"+e+"</p>");
				}
				
					
			}else{
				RequestDispatcher rd=request.getRequestDispatcher("Collect_Info"); 
				//out.println("<p>First name: "+request.getParameter("fname")+"</p>");
				rd.include(request, response);
			}

	}
	
}