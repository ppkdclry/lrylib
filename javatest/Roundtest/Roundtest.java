/**
* Description:����double��int����������<br>
* ProgramName:doubleתint����������<br>
* Date:2018/04/08
* @author Rongyi rongyifj@126.com
* @version 1.0
*/
public class Roundtest{
	/**
	* ������
	* @param args �����в���
	*/
	public static void main(String[] args)
	{
		double posd = 1.60;
		double negd = -1.60;
		System.out.println(Round(posd));
		System.out.println(Round(negd));
	}
	
	/**
	* ��������
	* @param d �����������˫����
	* @return �����������볤����
	*/
	public static long Round(double d)
	{
		if (d > 0.0){
			return (long)(d + 0.5);
		}else{
			return (long)(d - 0.5);
		}
	}
}