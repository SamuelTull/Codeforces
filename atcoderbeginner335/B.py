from collections import defaultdict
ans = defaultdict(set)
for x in range(22):
    for y in range(22):
        for z in range(22):
            for s in range(x+y+z, 22   ):
                ans[s].add((x, y, z)) 

print("ANS = {")
for s in range( 22):
    print(s, ": '", "\\n".join([f"{x} {y} {z}"  for x,y,z in sorted(ans[s])]), "',", sep="" )

print("}")    

