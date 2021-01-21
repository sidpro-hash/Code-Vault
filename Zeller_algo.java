
/*
 * # Do you know on which day you were born?If your friend's birthday is February 24th,
 *   what day of the week does it fall in year?you can answer these questions with
 *   a quick reference to an online calendar,But if you wanted to calculate this by hand,
 *   how would you go about doing it?
 *
 * # Zeller's congruence is an algorithm devised by Christian Zeller to calculate the day of
 *   the week for any Julian or Gregorian calendar date.It can be considered to be based on 
 *   the conversion between Julian day and the calendar date.
 *
 * h = (d + 26*(m+1)/10 + k + k/4 + j/4 + 5*j)%7
 *
 * where,
 *	h is the day of the week (0 = Saturday, 1 = Sunday, 2 = Monday,..., 6 = Friday).
 *	d is the day of the month.
 *	m is the month (3 = March, 4 = April, 5 = May,..., 14 = February).
 *	k the year of the century ( k = year mod 100).
 *	j is the zero-based century (j = floor(year/100) )For example, the zero-based centuries.
 *	for 1995 and 2000 are 19 and 20 respectively.
 *
 * # In this algorithm January and February are counted as months 13 and 14 of the previous year.
 *   E.g. if it is 2 February 2021, the algorithm counts the date as the second day of the 
 *   fourteenth month of 2020 (02/14/2020 in DD/MM/YYYY format). 
 */


import java.util.Scanner;
class Zeller_algo{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		String arr[] = {"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
		System.out.print("Enter year: ");
		int y = scan.nextInt();
		System.out.print("Enter month (1-12): ");
		int m = scan.nextInt();
		if(m==1){m=13;y--;}
		if(m==2){m=14;y--;}
		System.out.print("Enter date (1-31): ");
		int d = scan.nextInt();
		int j = y/100;
		int k = y%100;
		int h = (d+26*(m+1)/10+k+k/4+j/4+5*j)%7;
		System.out.println("Day of the week is "+arr[h]);		
	}
}