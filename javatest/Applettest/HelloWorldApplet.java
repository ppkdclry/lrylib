import java.applet.*;
import java.awt.*;

/**
* Description:<br>
* Copyright (C), 2018-2019, Rongyi.Lv<br>
* This program is protected by copyright laws.<br>
* Program Name: Applet testing.<br>
* Date: 2018/04/08<br>
* @author Rongyi.Lv rongyifj@126.com
* @version 1.0
*/
public class HelloWorldApplet extends Applet
{
	/**
	* ªÊÕº≥Ã–Ú
	* @param g ± À¢
	*/
	public void paint(Graphics g)
	{
		g.drawString("Hello World", 25, 50);
	}
}