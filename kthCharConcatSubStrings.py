# Enter your code here. Read input from STDIN. Print output to STDOUT
import sys
import math
import time

def printKthChar(string, K):
    length = len(string)
    substringList = []
    start = time.time()
    #obtain all substrings 
    for num in range(length):
        tmpstr = ''
        for jum in range(num, length):
            tmpstr+=string[jum]
            substringList.append(tmpstr)
    end = time.time()
    print "time taken to get all substrings", end - start
    start = time.time()
    #now sort the list lexicographically
    substringList.sort()
    #print substringList
    end = time.time()
    print "time taken to sort the substrings", end - start
    curPos = 0
    pos = 0
    prevElem = ''
    for elem in substringList:
        if prevElem == elem:
            continue
        prevElem = elem
        pos += len(elem)
        if pos > K-1:
            print elem[K-1 - curPos]
            return
        else:
            curPos = pos

string = "toefpqnvnqducsamtcmqiqyjazyhizgcnmjefzzurcpturfqtsgbkgnmfntombsbodftcgnukenfvvxrpdszlfoqvhghjylzcssgzhajoqqjnnacsvddcrwxbchkdslhkfnlmqvainmvbozvjeboyxlzbslemwnxbdiptfsdtgywuztgduubthavcnbojplmuwepdwswcquyroeuiayciaxkoaazrmolksanqsmskgsbuzyfzyhjygvogwqakelwymjogxiteauabufbsomtuijdgbdqfqmfexvlvdebgadhxjkrxxmuhwznxedfurmbqimllsotusdrdnlcmxwttxgtblayemzvuniihxbdrgvuugwiftcbskuwyuucgvxdkglrfouwvrqrzmzfhbgaocwmysogpojzuusbloxginxhbwolawloajcydqfsgqtallbyzaejpdtrbhcdgptiavhfooxueqxrdapebvoqahjcqlhwcbfcyohocglgyiabkpgnnwgndprtdzsfczkaprrraczykzawrikeeqtjflcikwqmvaokrfdthfstguqxccdisxrzivkusaipayctgfnnmhjtbbsfdynxvgwfdgbvilnkjpgpwtfjaocdruiwsxtpdrwgazeikrtugzjcuqlwepzxmjtegowlgutguxqeqlywmkbiaoghefgqqcwwqujypdejaxpriqpxcsfcjmlntsfmudkmaulpxrazorszhkyjcfolrbanvhbrnlenfreeieezvyyfiyqndgaxkdkfmlzzyfmewqiewodundzvbrifylcioopabocztofrhowfcbbphcniuxpuiteyjvzmkbmfrrxahvimyjbfmqqiohcydixmdwzpznvsgutordapmdxawnikumkxuhmyflneakzgguuxxwpjcmmyzuivhuvbcjbhupowzncghzfgvurxgdxhyhfhcckelmnhbbdcqfkzeqfcmxbtazcaghhijsowecdhfglymwxsofwaeavgzahhhqstkgrqkvzqblqphnkxugxygvfhvoreglxttpjemlwnwmdfbncyvbwcwdlrtewcpvvjmgnyrlmnzruaewybyxdwcroyvkanfvwsdlsvwekvxfxddyfdviazboxzaxmfuizytstryfoyklbolgtgrtishfthffpbpqzkkublarjmdkcorwxirhcbmwktbzvtswdcthpvyyhdlmuckrmbyocmmniqofjgbmluvcpubzxoltqvkeykubzhqjxeognpuamqcdmdclrpfjmrplekofreoqieyxvsxhkanyfrmzhrkvkagqmwvfalvlptilnisaihapzmoidzdqbmgnicslnpyfiiqxqkzasaqrmebsfeiisqvdupoiempoufmnpnnjndaakduricacuvfpntzrhogeturkjeuxkuzwatnkxnmrlsgynfrxtzbotszfytcipbepuuzrhmkugrstykqsjtiflhkmaowqpbhlxheevozbhtwgfpapiiwwqiisweklhsygbclysmbahxgnogezoavgifzgljtvdrbevocncdpkdvxtdbsudnanuztglmdodevavznxffhicedghwaklcxgesoperfjxcjsczqhexrgeuonsoaetzkxsaowrtgowphaqzjuwcdcwrqriqvbphahhogyjmohdvhwusqtuvvrpnixdfatmactqitzwhjcfqybjqudmswbfgalncgzeisutlvrvetaxrbikynyqkbxsbigfohjzcfupalkhfkeyomimzieljdgmoorevcdxhzpklzrsmvqajboijuwvxchlsbqndvnnvcxidoaplsruthcfdacbcjoumgksezfzdehgsjydbrxxbbcecehgpwdecpygodhrjqzdbzgdtfauieymkgtbewfindrbiyutrtwsvcxojxiubignqzpuxwdkcunmuhgndciyhfosdwmgetwvulrujuglquyndgagiigpouktswbxpxumkngukmhaghnknqswyznovxjowlnnihzvwfpguwhcgwotohrnifddenrayeoinpfkxusrtbtzykumrmbbtfezuwcucseqhkceguvzwrawbvkujmvetbdpzfjcxnufxylesjfqciodfzzonwsgxxxxdgbcvxhtvvzpegggoulvvmliifohdlggthipeskbnlrtrzzivmfryrzgwqnzduhxdsokmylblcuedvmzhuqflpnjfcllysicmyoawzbjexnhucgbwyihoxsvadgyyqckoqlmsovwojfilomjmuscskysogsmzxypnjcfazdokjyxxkgjhymzjmtxunlvkjlyvpfxojnbulytwfeddseogznbmyyxkjxfaccpnpsjcqcavhdbbjriifjvfhurtrwttakjrcsutxuqgathjnpuuapzkjrfapyvslgjnbdiyabgawnljffdhwfrfywhpxfhinrxowiowlwyhmktrpwymdstbqdrpkyzxrxoohemsblbnvuemreawywyrzrgjriijfwxoblgewhrtexgxditcetvfkdoclzlsxkgavoeuyvncstbweuaioxoaaecofpgdzpdxfirdfehyakwefyovxcvzjanopwtrlxoshhymlhmnsktxkiuhmphxpwmhsfyfeoalvyaifmyxzrwjbqtqgcnxybetjeansabnabygpwfqpcarsvhaxwyxyeshjvwbvzryaresnjiclkvgfegebgczlwiwrgzpgsnijtayclbqxywddejelnfykpubvvsdofmxyowdbzvzztecxnikbnileeoccjfqorppinujopioimqfazsdocqvhgxjpcbgwsvggppueaiombvocntsqjnzqkkhplnnditlzigfkqtxtpnvchouqbtiodqdqdquolfpvnvggqdzfsxkzlgsoaaedsjwybqmmxbinwotntsunpgncnhtnjxschqaigoxgpftovmdqgzdygqcvzvkjvenevpoddljuscknqpdxphvxzxsbvemqizwfokjtysnqxagnplkeuhdwfxxcbjumiqrycatavitsibfymsehzidgfcijlcvvumvxnozkyschtjhidlpdvuldwumjyhettzqiprsnkwwfidnlreooycrwyffwmjrikjsbbnrljnsrtgdmmtclvwjtbpsoajyntqqudhhpxbgsjlgwhijeesaghswkduzympuqzbfwfnqobykigtonmovvithmpgmbwhrviytpmlenjoxrilgwabtkubwjjjnhseecdxsrkwgvkdnuotsqxmbtpzfyksgcwkfbkxuwtasfdfasaskzgltvnywxqcaoohsaemxznpeswgmybxyhkrfxrbvhfxxtepuket"

printKthChar(string, 5665842)
'''
def main():
    return
    T = int(raw_input())
    for input in range(T):
        string = raw_input()
        K = int(raw_input())
        printKthChar(string, K)
    
    
#call the main function
main()
'''
