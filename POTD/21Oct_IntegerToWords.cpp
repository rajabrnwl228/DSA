/* Integer to Words (Medium Level)
Write a function to convert a given number into words.

Example 1:

Input:
N = 438237764
Output: forty three crore eighty two lakh
thirty seven thousand seven hundred and
sixty four


Example 2:

Input:
N = 1000
Output: one thousand
Expected Time Complexity: O(1)
Expected Auxiliary Space: O(1)
*/

string map1[20] = {"", "one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine ", "ten ", "eleven ", "twelve ", "thirteen ", "fourteen ", "fifteen ", "sixteen ", "seventeen ", "eighteen ", "nineteen "};
string map2[10] = {"", "", "twenty ", "thirty ", "forty ", "fifty ", "sixty ", "seventy ", "eighty ", "ninety "};
string convert(int n)
{
    int tens = n / 10;
    int ones = n % 10;
    string ans = "";
    if (tens == 0 || tens == 1)
    {
        ans = ans + map1[n];
    }
    else
    {
        ans = ans + map2[tens] + map1[ones];
    }
    return ans;
}
string convertToWords(long num)
{
    // code here
    int c = num / 10000000;
    int l = (num / 100000) % 100;
    int t = (num / 1000) % 100;
    int h = (num / 100) % 10;
    int to = (num) % 100;
    string ans = "";
    if (c > 0)
    {
        string subans = convert(c);
        ans = ans + subans + "crore ";
    }
    if (l > 0)
    {
        string subans = convert(l);
        ans = ans + subans + "lakh ";
    }
    if (t > 0)
    {
        string subans = convert(t);
        ans = ans + subans + "thousand ";
    }
    if (h > 0)
    {
        string subans = convert(h);
        ans = ans + subans + "hundred ";
    }
    if (to > 0)
    {
        string subans = convert(to);
        if (num > to)
        {
            ans = ans + "and ";
        }
        ans = ans + subans;
    }

    return ans;
}