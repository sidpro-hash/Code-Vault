
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



// First method of creating servlet
public class Validation_Login extends HttpServlet{
	private String message;
	
	public void init() throws ServletException{
		message = "Validating Employee Login";
	}
	
	public void doPost(HttpServletRequest request,HttpServletResponse response) throws ServletException,IOException{
		response.setContentType("text/html");
		PrintWriter out = response.getWriter();
		//String ppath = request.getContextPath();
		
		String username = request.getParameter("uname");
		String pass = request.getParameter("pass");
		boolean go = true;
			
			
				
				ServletContext config=getServletContext();  
				String classname =  config.getInitParameter("classname");
				String url =  config.getInitParameter("url");
				String uname = config.getInitParameter("username");
				String password = config.getInitParameter("password");

				try {
					Class.forName(classname);
				}catch(Exception e) {e.printStackTrace();}
				
				try(Connection con = DriverManager.getConnection(url,uname,password);){

					Statement stmt = con.createStatement();
					ResultSet rs = stmt.executeQuery("SELECT * FROM emp10 WHERE firstname='"+username+"' AND ROWNUM <= 1");
					while(rs.next()){
						if(rs.getString(6).equals(pass))go=false;
					}
					stmt.close();
				}
				catch(SQLException e){
					
					out.println("<p>"+e+"</p>");
				}
				catch(Exception e){
					
					out.println("<p>"+e+"</p>");
				}
				
					
			if(go){
				RequestDispatcher rd=request.getRequestDispatcher("Login"); 
				request.setAttribute("fname_error", " Username Or Password is Wrong !");
				//out.println("<p>First name: "+request.getParameter("fname")+"</p>");
				rd.include(request, response);
			}else{
				response.sendRedirect("Display_Info");
			}

	}
	
}