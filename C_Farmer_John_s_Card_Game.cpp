import java.util.*

fun codeWithLove(cards: List<List<Int>>, p: List<Int>, n: Int, m: Int): Boolean {
    var last = -1
    val pos = IntArray(n) { 0 }
    
    for (round in 0 until m) {
        for (i in 0 until n) {
            val cow = p[i] - 1
            if (pos[cow] >= m || cards[cow][pos[cow]] <= last) {
                return false
            }
            last = cards[cow][pos[cow]]
            pos[cow]++
        }
    }
    return true
}

fun main() {
    val scanner = Scanner(System.`in`)
    val t = scanner.nextInt()
    
    repeat(t) {
        val n = scanner.nextInt()
        val m = scanner.nextInt()
        
        val cards = List(n) { MutableList(m) { scanner.nextInt() } }
        val first = mutableListOf<Pair<Int, Int>>()
        val last = mutableListOf<Pair<Int, Int>>()
        
        for (i in 0 until n) {
            cards[i].sort()
            first.add(Pair(cards[i][0], i))
            last.add(Pair(cards[i][m - 1], i))
        }
        
        val order = (0 until n).sortedWith(compareBy({ first[it].first }, { last[it].first }))
        val p = order.map { it + 1 }
        
        if (codeWithLove(cards, p, n, m)) {
            println(p.joinToString(" "))
        } else {
            println("-1")
        }
    }
}
