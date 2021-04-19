 <!DOCTYPE html> 
 <html> 

 <head> 
	 <title> Jsp By Sid </title> 
	 <meta charset="utf-8"> 
	 <meta name="author" content="SidPro"/> 
	 <meta name="viewport" content="width=device-width,initial-scale=1"> 
	 <link type="text/css" rel="stylesheet" href="Login.css"> 
 </head> 

 <body> 
	 <div class="login"> 
	 <h1>Login</h1> 
	 <% String fname ="";
		if(request.getAttribute("fname_error")!=null){
			fname=(String)request.getAttribute("fname_error");
			request.removeAttribute("fname_error");
		} %>
	 <span style="color:#f24835"><%= fname %></span> 
	 <form action="validate_Login" method="post"> 
	 <input type="text" name="uname" placeholder="Username" required="required" /> 
	 <input type="password" name="pass" placeholder="Password" required="required" /> 
	 <button type="submit" class="btn btn-primary btn-block btn-large">Let me in.</button> 
	 <p>Don't have an account? <a href="register_user.jsp" target="_self">Sing up here!</a></p> 
	 </form> 
	 </div> 

 </body> 
 </html> 