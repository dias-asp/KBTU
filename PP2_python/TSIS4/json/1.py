import json

f = open(r"C:\codes\python\Test\json\js.json")
x = json.load(f)

print("Interface Status\n")
print("================================================================================")
print("DN                                                 Description           Speed    MTU  ")
print("-------------------------------------------------- --------------------  ------  ------")
for object in x["imdata"]:
    object1 = object["l1PhysIf"]["attributes"]
    print(f'{object1["dn"]}                              {object1["speed"]}   {object1["mtu"]}')