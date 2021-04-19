<%@ page import="java.sql.*" %>
<%
		
 		String username = request.getParameter("uname");
		String pass = request.getParameter("pass");
		boolean go = true;
				
				String classname =  application.getInitParameter("classname");
				String url =  application.getInitParameter("url");
				String uname = application.getInitParameter("username");
				String password = application.getInitParameter("password");

				try {
					Class.forName(classname);
				}catch(Exception e) {e.printStackTrace();}
				
				try{
					Connection con = DriverManager.getConnection(url,uname,password);
					Statement stmt = con.createStatement();
					ResultSet rs = stmt.executeQuery("SELECT * FROM user_jsp WHERE firstname='"+username+"' AND ROWNUM <= 1");
					while(rs.next()){
						if(rs.getString(5).equals(pass)){
							go=false;
							if (session.isNew()){
								session.setAttribute("username",username);
							}
						}
					}
					stmt.close();
					con.close();
				}
				catch(SQLException e){
					
					out.println("<p>"+e+"</p>");
				}
				catch(Exception e){
					
					out.println("<p>"+e+"</p>");
				}
					
			if(go){
				
				request.setAttribute("fname_error", " Username Or Password is Wrong !");
				//out.println("<p>First name: "+request.getParameter("fname")+"</p>");  %>
				<jsp:include page="Login.jsp"/>    
<%			}else{
				
				response.sendRedirect("five_marks.jsp");
				
			}
%>