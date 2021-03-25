
import java.io.IOException;
import java.io.PrintWriter;


import javax.servlet.ServletException;
import javax.servlet.ServletConfig;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpSession;
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
public class Display_Info extends HttpServlet{
	private String message;
	
	public void init() throws ServletException{
		message = "Displaying Employee information";
	}
	
	public void service(HttpServletRequest request,HttpServletResponse response) throws ServletException,IOException{
		response.setContentType("text/html");
		PrintWriter out = response.getWriter();
		//String ppath = request.getContextPath();
		String username = "";
		HttpSession session=request.getSession(false);  
		if(session==null){
			response.sendRedirect("Login");
		}else{
			
			username=(String)(session.getAttribute("username")==null?"":session.getAttribute("username"));
			if(username.equals("")){
					response.sendRedirect("Login");
			}
		}
		
		out.println("<!DOCTYPE html>");
		out.println("<html>");
		
		out.println("<head>");
			out.println("<title> Servlet By Sid </title>");
			out.println("<meta charset=\"utf-8\">");
			out.println("<meta name=\"author\" content=\"SidPro\"/>");
			out.println("<meta name=\"viewport\" content=\"width=device-width,initial-scale=1\">");
			out.println("<link type=\"text/css\" rel=\"stylesheet\" href=\"Display_Info.css\">");
			/*out.println("<script>");
			out.println("function CloseS(){");
			out.println("window.location.href=\"Logout\";}");
			out.println("</script>");*/
		out.println("</head>");
		
		out.println("<body>");
			out.println("<h2> "+message+" | <a href=\"Collect_Info\" target=\"_self\"> Register Here </a> | <a href=\"Logout\"> Logout </a></h2>");
			out.println("<p>UserName :"+username+"</p>");
			ServletConfig config=getServletConfig();  
				String classname =  config.getInitParameter("classname");
				String url =  config.getInitParameter("url");
				String uname = config.getInitParameter("username");
				String password = config.getInitParameter("password");

				try {
					Class.forName(classname);
				}catch(Exception e) {e.printStackTrace();}
				
				try(Connection con = DriverManager.getConnection(url,uname,password);){

					
					Statement stmt1 = con.createStatement();
					ResultSet rs = stmt1.executeQuery("SELECT * FROM emp10");
					out.println("<table>");
					out.println("<tr><th>EMAIL</th><th>LASTNAME</th><th>FIRSTNAME</th><th>GENDER</th><th>EXPERIENCE</th><th>PASSWORD</th></tr>");
					while(rs.next()){
						
						out.println("<tr><td>"+rs.getString(1)+"</td>"+"<td>"+rs.getString(2)+"</td>"+"<td>"+rs.getString(3)+"</td>"+"<td>"+rs.getString(4)+"</td>"+"<td>"+rs.getString(5)+"</td>"+"<td>"+rs.getString(6)+"</td></tr>");
						
					}
					stmt1.close();
					out.println("</table>");
				}
				catch(SQLException e){
					
					out.println("<p>"+e+"</p>");
				}
				catch(Exception e){
					
					out.println("<p>"+e+"</p>");
				}

		out.println("</body>");
		out.println("</html>");
		 
	}
	
}