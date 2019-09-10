/*
	题目要求（找不到原题）	数字以01234567891011121314...的格式排列。在这个序列中，第5位（从0开始计）是5，第13位是1，第19位是4。求任意第n为对应的数字。
*/
/*
以第15位数字2为例（2隶属与12，两位数，位于12从左侧以0号开始下标为1的位置）
步骤1：首先确定该数字是属于几位数的;
      如果是一位数，n<9;如果是两位数，n<9+90*2=189;
      说明是两位数。
步骤2：确定该数字属于哪个数。10+(15-10)/2= 12。
步骤3：确定是该数中哪一位。15-10-(12-10)*2 = 1, 所以位于“12”的下标为1的位置，即数字2。

以第1001位数字7为例
步骤1：首先确定该数字是属于几位数的;
      如果是一位数，n<9;如果是两位数，n<9+90*2=189;如果是三位数，n<189+900*3=2889;
      说明是三位数。
步骤2：确定该数字属于哪个数。100+(1001-190)/3= 370。
步骤3：确定是该数中哪一位。1001-190-(370-100)*3 = 1,所以位于“370”的下标为1的位置，即数字1。

作者：ryderchan
链接：https://www.jianshu.com/p/0bbf1fcbe070
来源：简书
简书著作权归作者所有，任何形式的转载都请联系作者获得授权并注明出处。
*/

public int getDigitAtIndex(int index) {
	if (index < 0)
		return -1;
	int place = 1; // 1 表示个位，2 表示 十位...
	while (true) {
		int amount = getAmountOfPlace(place);
		int totalAmount = amount * place;
		if (index < totalAmount)
		return getDigitAtIndex(index, place);
		index -= totalAmount;
		place++;
	}
}
/**
* place 位数的数字组成的字符串长度
* 10, 90, 900, ...
*/
private int getAmountOfPlace(int place) {
	if (place == 1)
		return 10;
	return (int) Math.pow(10, place - 1) * 9;
}
/**
* place 位数的起始数字
* 0, 10, 100, ...
*/
private int getBeginNumberOfPlace(int place) {
	if (place == 1)
		return 0;
	return (int) Math.pow(10, place - 1);
}
/**
* 在 place 位数组成的字符串中，第 index 个数
*/
private int getDigitAtIndex(int index, int place) {
	int beginNumber = getBeginNumberOfPlace(place);
	int shiftNumber = index / place;
	String number = (beginNumber + shiftNumber) + "";
	int count = index % place;
	return number.charAt(count) - '0';
}


//以下简书参考答案
/**
 * Created with IntelliJ IDEA
 * Author: ryder
 * Date  : 2017/8/3
 * Time  : 8:50
 * Description:数字序列中某一位的数字
 **/
public class P225_DigitsInSequence {
    public static int digitAtIndex(int index){
        if(index<0)
            return -1;
        if(index<10)
            return index;
        int curIndex = 10,length = 2;
        int boundNum = 10;
        while (curIndex+lengthSum(length)<index){
            curIndex+=lengthSum(length);
            boundNum*=10;
            length++;
        }
        int addNum = (index-curIndex)/length;
        int curNum = boundNum + addNum;
        return Integer.toString(curNum).charAt(index-curIndex-addNum*length)-'0';
    }
    public static int lengthSum(int length){
        int count = 9;
        for(int i=1;i<length;i++)
            count*=10;
        return count*length;
    }
    public static void main(String[] args){
        for(int i=9;i<16;i++)
            System.out.println(digitAtIndex(i));
        System.out.println(digitAtIndex(1001));

    }
}
