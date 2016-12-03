import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.UnknownHostException;

public class Client {
	
	private Socket socket;
	private PrintWriter out;
	private BufferedReader in;
    

	public Client(int port) throws IOException, UnknownHostException {
		socket = new Socket("127.0.0.1", port);

        out = new PrintWriter(socket.getOutputStream(), true);
        in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
	}
	
	public int getFaceNumber() throws NumberFormatException, IOException {
		out.println("\n");
		return Integer.parseInt(in.readLine().replace("\n", ""));
    }
	
	public void destroy() throws IOException {
		socket.close();
	}
}