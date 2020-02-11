你的朋友正在使用键盘输入他的名字 name。偶尔，在键入字符 c 时，按键可能会被长按，而字符可能被输入 1 次或多次。
你将会检查键盘输入的字符 typed。如果它对应的可能是你的朋友的名字（其中一些字符可能被长按），那么就返回 True。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/long-pressed-name


class Solution {
public:
    bool isLongPressedName(string name, string typed)
     {       
        int l1 = name.size(), l2 = typed.size();
        if(l2 < l1)
            return false;  
        int i = 0, j = 0;
        while(i < l1 && j < l2)
        {
            if(name[i] == typed[j])
                i++;
            j++;
        }
        if(i == l1)
            return true;
        return false;
    }
};