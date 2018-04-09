/**
* Descriptor:double型和int型混合运算测试
* ProgramName:混合类型运算结果
* @author Rongyi 641093277@qq.com
* @version 1.0
*/
public class OperateTest{
	/**
	* 主函数
	* @param args 命令行参数
	*/
	public static void main(String[] args)
	{
		System.out.println(1 + 4/5 + (int)5.2/2.5);
		System.out.println(1 + 4/5 + (int)(5.2/2.5));
		System.out.println(1 + 4/5 + 5.2/2.5);
		System.out.println(1.0 + 4/5 + 5.2/2.5);
		System.out.println(1 + 4/5.0 + 5.2/2.5);
	}
}