/*
 *        **** The WebCrawler class ****
 *
 * # What is Web Crawler?
 * # Program that automatically traverses the documents on the Web by following
 *   the hyperlinks. This type of program is commonly known as a Web crawler. 
 *
 * # This program follows for the hyperlinks that starts with http:// or https://
 *   and Ignore .js,.png,.css,.jpg and .ico types hyperlinks.Traversed links limit is 100. 
 *
 * https://soundcloud.com
 *
 * # References:
 *   https://bit.ly/3sPNZQv
 *   https://bit.ly/3qMLFHR
 *   https://bit.ly/3p7n9Rq
 *
 */

import java.util.*;
import java.net.*;
import java.io.*;

class WebCrawler{
	public static void main(String args[]){
		System.out.println("Enter a URL: ");
		String url_name = new Scanner(System.in).next();
		try{
			URL url = new URL(url_name.trim());
			HttpURLConnection hcon = (HttpURLConnection)url.openConnection();
			int r = hcon.getResponseCode();
			System.out.println("ResponseCode: "+r);
			hcon.disconnect();
			Crawl(url_name);
		}catch(MalformedURLException e){
			System.out.println("Invalid URL or URL not exist");
		}catch(ConnectException e){
			System.out.println("Error: "+e.getMessage());
		}catch(IOException e){
			System.out.println("Error: Unable to Connect");
		}catch(Exception e){
			System.out.println(e.getMessage());
		}
	}
	
	static void Crawl(String StartingURL){
		ArrayList<String> PendingURLs = new ArrayList<>();
		ArrayList<String> TraversedURLs = new ArrayList<>();

		PendingURLs.add(StartingURL);
		while(!PendingURLs.isEmpty() && TraversedURLs.size() <=100){
			String url = PendingURLs.remove(0);
			if(!TraversedURLs.contains(url)){
				TraversedURLs.add(url);	
				System.out.println("Crawl "+url);
			}
			for(String Url: getSubURLs(url)){
				if(!TraversedURLs.contains(Url))
					PendingURLs.add(Url);
			}
			//System.out.println("TraversedURLs.size() :"+TraversedURLs.size());
		}
	}

	static ArrayList<String> getSubURLs(String urlName){
		ArrayList<String> listOfSubURLs = new ArrayList<>();
		try{
			URL url = new URL(urlName);
			Scanner scan = new Scanner(url.openStream());
			
			int index_http = 0,png=0,jpg=0,css=0,ico=0,js=0;
			while(scan.hasNext()){
					String line = scan.nextLine();
					
					index_http = line.indexOf("https:",index_http);
					if(index_http<0)index_http = line.indexOf("http:",index_http);
					while(index_http>0){
							int endIndex = line.indexOf("\"",index_http);
							if(endIndex>0){
									String link = line.substring(index_http,endIndex).trim();
									png = link.indexOf(".png",-6);
									jpg = link.indexOf(".jpg",-6);
									js = link.indexOf(".js",-6);
									css = link.indexOf(".css",-6);
									ico = link.indexOf(".ico",-6);
									if(png<0 && jpg<0 && css<0 && js<0 && ico<0)listOfSubURLs.add(link);
									index_http = line.indexOf("https:",endIndex);
									if(index_http<0)index_http = line.indexOf("http:",endIndex);
							}
							else index_http = -1;
					}
			}
			
		}catch(MalformedURLException e){
			System.out.println("Error: Invalid URL or URL not exist");
		}catch(ConnectException e){
			System.out.println("Error: "+e.getMessage());
		}catch(IOException e){
			System.out.println("Error: Unable to Connect");
		}
		return listOfSubURLs;
	}
}