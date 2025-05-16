import java.util.*

fun main() {
    val reader = Scanner(System.`in`)
    val t = reader.nextInt()
    
    repeat(t) {
        val scanner = Scanner(System.`in`)
    val n = scanner.nextInt()
    val x = scanner.nextInt()
    val y = scanner.nextInt()
    val a = IntArray(n) { scanner.nextInt() }
    val ms = TreeMap<Int, Int>()
    var sum = 0
    
    for (num in a) {
        sum += num
        ms[num] = ms.getOrDefault(num, 0) + 1
    }
    
    var ans = 0
    
    for (i in 0 until n) {
        val one = sum - a[i]
        val l = one - x
        val r = one - y
        
        val tmp1 = ms.headMap(r, false).values.sum()
        val tmp2 = ms.headMap(l + 1, false).values.sum()
        
        ans += if (a[i] in r..l) (tmp2 - tmp1 - 1) else (tmp2 - tmp1)
    }
    
    ans /= 2
    println(ans)
    }
}
