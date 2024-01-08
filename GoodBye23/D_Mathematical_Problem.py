# SETS = {
#     1: ["1"],
#     3: ["169", "196", "961"],
#     5: [
#         "16384",
#         "31684",
#         "36481",
#         "38416",
#         "43681",
#     ],
# }


# for n in range(7, 12, 2):
#     SETS[n] = []
#     start = int((10 ** (n - 1)) ** (1 / 2))
#     end = int((10**n) ** (1 / 2))
#     cnt = {}
#     for i in range(start, end + 1):
#         num = i * i
#         digits = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
#         while num:
#             digits[num % 10] += 1
#             num //= 10
#         cnt[tuple(digits)] = cnt.get(tuple(digits), 0) + 1
#     max_cnt = 0
#     for k, v in cnt.items():
#         if v > max_cnt:
#             max_cnt = v
#             max_digits = k
#     i = start
#     while i <= end and len(SETS[n]) < (99 if n == 11 else n):
#         num = i * i
#         digits = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
#         while num:
#             digits[num % 10] += 1
#             num //= 10
#         if digits == list(max_digits):
#             SETS[n].append(str(i * i))
#         i += 1


SETS = {
    1: ["1"],
    3: ["169", "196", "961"],
    5: ["16384", "31684", "36481", "38416", "43681"],
    7: ["1006009", "1060900", "1690000", "1960000", "6100900", "9006001", "9060100"],
    9: [
        "139854276",
        "152843769",
        "157326849",
        "215384976",
        "245893761",
        "254817369",
        "326597184",
        "361874529",
        "375468129",
    ],
    11: [
        "10057482369",
        "10208475369",
        "10859307264",
        "12938607504",
        "13470852096",
        "13985427600",
        "14050783296",
        "14809673025",
        "15284376900",
        "15309607824",
        "15732684900",
        "16203507849",
        "16375809024",
        "17049830625",
        "17206093584",
        "17345680209",
        "17530289604",
        "17689532004",
        "18497360025",
        "20134758609",
        "20635897104",
        "20851937604",
        "20859736041",
        "20897015364",
        "21538497600",
        "21753890064",
        "23054170896",
        "23081509476",
        "24589376100",
        "25083907641",
        "25481736900",
        "25713084609",
        "25874009316",
        "25930016784",
        "25936780401",
        "26913058704",
        "27003691584",
        "27058934016",
        "27905368401",
        "28391576004",
        "28403709156",
        "29754180036",
        "30264517089",
        "30410825769",
        "30829741056",
        "30902475681",
        "31807652409",
        "32059618704",
        "32659718400",
        "34900217856",
        "35042716809",
        "35047209681",
        "35249687001",
        "35600897124",
        "35907218064",
        "36108740529",
        "36187452900",
        "36805271409",
        "37018529604",
        "37019684025",
        "37546812900",
        "37984061025",
        "38294576100",
        "38417960025",
        "38529764100",
        "39207564081",
        "40053217689",
        "40305782169",
        "40935810276",
        "41273985600",
        "41602537089",
        "41753200896",
        "43678910025",
        "45038601729",
        "45090823716",
        "45231080976",
        "45390728601",
        "48621573009",
        "48702310596",
        "49370618025",
        "50201987364",
        "50704681329",
        "51072836049",
        "52381476900",
        "52908740361",
        "52987436100",
        "53721968400",
        "53968400721",
        "54800937216",
        "54807960321",
        "54938672100",
        "57408639201",
        "58743216900",
        "58932417600",
        "59608734201",
        "59736248100",
        "60054893721",
        "61538724900",
        "62017435089",
    ],
}


out = []
for _ in range(int(input())):
    n = int(input())
    if n < 11:
        out += SETS[n]
    else:
        out += [s + "0" * (n - 11) for s in SETS[11][:n]]

print("\n".join(out))