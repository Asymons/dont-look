import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.SWT;
import org.eclipse.swt.widgets.Text;
import org.eclipse.swt.widgets.Label;
import org.eclipse.wb.swt.SWTResourceManager;

public class Dont {

	protected Shell shlDontLook;

	/**
	 * Launch the application.
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			Dont window = new Dont();
			window.open();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	/**
	 * Open the window.
	 */
	public void open() {
		Display display = Display.getDefault();
		createContents();
		shlDontLook.open();
		shlDontLook.layout();
		while (!shlDontLook.isDisposed()) {
			if (!display.readAndDispatch()) {
				display.sleep();
			}
		}
	}

	/**
	 * Create contents of the window.
	 */
	protected void createContents() {
		shlDontLook = new Shell();
		shlDontLook.setSize(450, 300);
		shlDontLook.setText("Don't Look - Privacy in Real Life");
		
		Button btnNotifications = new Button(shlDontLook, SWT.CHECK);
		btnNotifications.setBounds(212, 159, 120, 33);
		btnNotifications.setText("Notifications");
		
		Button btnScreenDim = new Button(shlDontLook, SWT.CHECK);
		btnScreenDim.setBounds(111, 159, 95, 33);
		btnScreenDim.setText("Screen Dim");
		
		Button btnEnable = new Button(shlDontLook, SWT.NONE);
		btnEnable.setBounds(111, 240, 95, 28);
		btnEnable.setText("Enable");
		
		Button btnDisable = new Button(shlDontLook, SWT.NONE);
		btnDisable.setBounds(212, 240, 95, 28);
		btnDisable.setText("Disable");
		
		Label lblTitle = new Label(shlDontLook, SWT.NONE);
		lblTitle.setFont(SWTResourceManager.getFont(".Helvetica Neue DeskInterface", 24, SWT.NORMAL));
		lblTitle.setBounds(161, 10, 120, 33);
		lblTitle.setText("Don't Look");

	}
}
