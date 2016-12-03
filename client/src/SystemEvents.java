import java.awt.AWTException;
import java.awt.Robot;
import java.awt.event.KeyEvent;
import java.io.IOException;

public class SystemEvents {
	public static Robot r;
	public SystemEvents() throws AWTException{
		r = new Robot();
	}
	
	public static void dimScreen(){
		    Runtime runtime = Runtime.getRuntime();
		    String[] args = { "osascript", "-e", "tell application \"System Events\" to key code 107"};
		    String[] args2 = {"osascript", "-e" , "tell application \"System Events\" to key code 113"};

		    try
		    {
		    	for(int i = 0; i < 16; i++){
		    		Process process = runtime.exec(args);
		    	}
		    	
		    	for(int i = 0; i < 2; i++){
		    		Process process2 = runtime.exec(args2);
		    	}
		      
		      
		    }
		    catch (IOException e)
		    {
		      e.printStackTrace();
		    }
	}
	
	
	public static void dimMyScreen(){
		r.keyPress(KeyEvent.VK_F1);
	}
	
	
	
}
