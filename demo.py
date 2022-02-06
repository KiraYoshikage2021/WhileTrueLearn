import random
import time

playername = input('勇者，请输入你的名字：')

player_life = random.randint(100, 150)
player_attack = random.randint(30, 50)
enemy_life = random.randint(100, 150)
enemy_attack = random.randint(30, 50)

print(playername + '\n' + '血量：' + str(player_life) + '\n攻击：' +
      str(player_attack))
print('------------------------')
time.sleep(1)
print('【敌人】\n' + '血量：' + str(enemy_life) + '\n攻击：' + str(enemy_attack))
print('------------------------')
time.sleep(1)

while player_life > 0 and enemy_life > 0:
    if enemy_life >= player_attack:
        enemy_life = enemy_life - player_attack
    else:
        enemy_life = 0
    if enemy_life > 0:
        if player_life >= enemy_attack:
            player_life = player_life - enemy_attack
        else:
            player_life = 0
    else:
        print('你发起了攻击，【敌人】剩余血量' + str(enemy_life))
        break
    print('你发起了攻击，【敌人】剩余血量' + str(enemy_life))
    print('敌人向你发起了攻击，' + playername + '剩余血量' + str(player_life))
    print('-----------------------')
    time.sleep(1.5)

if player_life > 0 and enemy_life <= 0:
    print('今日份的胜负：属于' + playername)
elif player_life <= 0 and enemy_life > 0:
    print('菜')

input('请按任意键退出')
