package com.sidpro;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Statement;

import javax.faces.bean.ManagedBean;

@ManagedBean
public class Student {
	private String firstName; 	// Student first name
	private String lastName; 	// Student last name
	private String password; 		// Student password
	private String gender; 		// Student gender
	private String enNo; 			// Student Enrollment no
	/**
	 * 
	 */
	public Student() {
	}
	/**
	 * @return the firstName
	 */
	public String getFirstName() {
		return firstName;
	}
	/**
	 * @param firstName the firstName to set
	 */
	public void setFirstName(String firstName) {
		this.firstName = firstName;
	}
	/**
	 * @return the lastName
	 */
	public String getLastName() {
		return lastName;
	}
	/**
	 * @param lastName the lastName to set
	 */
	public void setLastName(String lastName) {
		this.lastName = lastName;
	}
	/**
	 * @return the password
	 */
	public String getPassword() {
		return password;
	}
	/**
	 * @param password the password to set
	 */
	public void setPassword(String password) {
		this.password = password;
	}
	/**
	 * @return the gender
	 */
	public String getGender() {
		return gender;
	}
	/**
	 * @param gender the gender to set
	 */
	public void setGender(String gender) {
		this.gender = gender;
	}
	/**
	 * @return the enNo
	 */
	public String getEnNo() {
		return enNo;
	}
	/**
	 * @param enNo the enNo to set
	 */
	public void setEnNo(String enNo) {
		this.enNo = enNo;
	}
	
	public boolean save(){  
		int result = 0;  
		try{  
			long eno = Long.valueOf(this.getEnNo());
			Class.forName("oracle.jdbc.driver.OracleDriver");     
			Connection con = DriverManager.getConnection( "jdbc:oracle:thin:@localhost:1521:XE","admin","admin");  
			PreparedStatement stmt = con.prepareStatement("INSERT INTO user_jsp VALUES(?,?,?,?,?)");  
			stmt.setLong(1,eno);
			stmt.setString(2,this.getLastName());
			stmt.setString(3,this.getFirstName());
			stmt.setString(4,this.getGender());
			stmt.setString(5,this.getPassword());
			result = stmt.executeUpdate(); 
			stmt.close();  
		}catch(Exception e){  
			System.out.println(e);  
		}  
		if(result == 1){  
			return true;  
		}else return false;  
	}  
		  
	public String submit(){  
		if(this.save()){  
			return "login.xhtml";  
		}else return "register.xhtml";  
	}
	
	public String check(){
		boolean go =true;
		try{  
			
			Class.forName("oracle.jdbc.driver.OracleDriver");     
			Connection con = DriverManager.getConnection( "jdbc:oracle:thin:@localhost:1521:XE","admin","admin");  
			Statement stmt = con.createStatement();
			ResultSet rs = stmt.executeQuery("SELECT * FROM user_jsp WHERE firstname='"+this.getFirstName()+"' AND ROWNUM <= 1");
			while(rs.next()){
				if(rs.getString(5).equals(this.getPassword())){
					go=false;	
				}
			}
			stmt.close();
			con.close();
		}catch(Exception e){  
			System.out.println(e);  
		}
		if(go)return "login.xhtml";
		return "marks.xhtml";
	}
}
