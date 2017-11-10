/**
*Description:RSA���ܲ���
*<br/>�������֣�RSA���ܲ���
*<br/>���ڣ�2017��11��09��
*@author б����¥ 641093277@qq.com
*@version 1.0
*/
import java.security.KeyPairGenerator;
import java.security.KeyPair;
import java.security.Security;
import java.security.NoSuchAlgorithmException;
import java.security.Provider;
import java.security.PublicKey;
import java.security.PrivateKey;

public class RSATest{
	public static void main(String[] args){
		System.out.println("RSA����");
		KeyPairGenerator keyPairGenerator;
		try{
			Security.addProvider(new com.sun.crypto.provider.SunJCE());
			keyPairGenerator = KeyPairGenerator.getInstance("RSA");
			if(keyPairGenerator != null){
				keyPairGenerator.initialize(1024);
				KeyPair keyPair = keyPairGenerator.generateKeyPair();
				PublicKey publicKey = keyPair.getPublic();
				PrivateKey privateKey = keyPair.getPrivate();
				System.out.println("publicKey:" + bytesToHexString(publicKey.getEncoded()));
				System.out.println("privateKey:" + bytesToHexString(privateKey.getEncoded()));
			}
		}catch(NoSuchAlgorithmException e){
			e.printStackTrace();
		}
	}
	
	public static String bytesToHexString(byte[] src){
		StringBuilder stringBuilder = new StringBuilder("");
		if(null == src || src.length <= 0){
			return null;
		}
		for(int i = 0;i < src.length;i++){
			int v = src[i] & 0xff;
			String hv = Integer.toHexString(v);
			if(hv.length() < 2){
				stringBuilder.append(0);
			}
			stringBuilder.append(hv);
		}
		return stringBuilder.toString();
	}
	
	public static String string2Unicode(String string)
	{
		StringBuffer unicode = new StringBuffer();
		
		for(int i=0;i<string.length();i++)
		{
			//ȡ��һ���ַ�
			char c = string.charAt(i);
			
			//ת��Ϊunicode
			unicode.append("\\u"+Integer.toHexString(c));
		}
		System.out.println(string.length());
		return unicode.toString();
	}
}