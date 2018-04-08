/**
* Description:测试double到int的四舍五入<br>
* ProgramName:double转int的四舍五入<br>
* Date:2018/04/08
* @author Rongyi rongyifj@126.com
* @version 1.0
*/
public class Roundtest{
	/**
	* 主函数
	* @param args 命令行参数
	*/
	public static void main(String[] args)
	{
		double posd = 1.60;
		double negd = -1.60;
		System.out.println(Round(posd));
		System.out.println(Round(negd));
	}
	
	/**
	* 四舍五入
	* @param d 待四舍五入的双精度
	* @return 返回四舍五入长整型
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