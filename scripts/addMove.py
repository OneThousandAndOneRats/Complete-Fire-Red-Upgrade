import os

def joinLine(line):
    new = ''
    for i in range(0,len(line)):
        if(i != 2):
            new += line[i] + ' '
        else:
            new+= line[i]
    if(new[len(new)-1] ==' '):
        new = new[:len(new)-1]
    new+='\n'
    return new

    
def addMoveH(directory):
    text = open(directory+'\\moves.h')
    lines = text.readlines()
    print("add new move named: MOVE_")
    moveName = input()
    moveName = 'MOVE_'+moveName.upper().replace(' ', '_')
    print(moveName)

    added = False
    hexx = 0
    
    for i in range(0,len(lines)):
        if(added and lines[i][8:13]== 'MOVE_'):
            spl = lines[i].split(' ')
            hexx = hex(int(hexx,16) +1).upper().replace('X','x')
            if ( '/' in lines[i]):
                for ch in range(0,len(spl[2])):
                    if(spl[2][ch] == '\t' or spl[2][ch] =="/"):
                       spl.insert(3,spl[2][ch:])
                       spl[len(spl)-1] = spl[len(spl)-1].strip()
                       #print(spl)
                       break
            spl[2] = hexx
            lines[i] = joinLine(spl)    
            #lines[i] = ' '.join(spl) + '\n'
            
            
        elif (lines[i] == '//Z-Moves\n'):
            prevHex = int(lines[i-2].split(' ')[2],16)
            hexx = hex(prevHex+1).upper().replace('X','x')
            lines[i-1] = '#define '+moveName + ' ' + hexx+'\n\n'
            added = True

        elif (lines[i][0:24] == '#define NON_Z_MOVE_COUNT'):
            lines[i] = '#define NON_Z_MOVE_COUNT   ('+moveName+ ' + 1)\n'

    
    with open(directory+'\\moves.h', 'w', encoding='utf-8') as file:
        file.writelines(lines)
    return moveName

def addMoveASM(directory,moveName):
    text = open(directory+'\\asm_defines.s')
    lines = text.readlines()
    #print("add new move named: MOVE_")
    #name = input()
    #name = 'MOVE_'+name.upper().replace(' ', '_')
    #print(name)

    added = False
    hexx = 0

    for i in range(0,len(lines)):
        
        if(added and lines[i][0] == '@'):
            break
        elif(added and lines[i][0]!= '@' and len(lines[i]) > 2):
            spl = lines[i].split(' ')
            hexx = hex(int(hexx,16) +1).upper().replace('X','x')
            if ( '/' in lines[i]):
                for ch in range(0,len(spl[2])):
                    if(spl[2][ch] == '\t' or spl[2][ch] =="/"):
                       spl.insert(3,spl[2][ch:])
                       spl[len(spl)-1] = spl[len(spl)-1].strip()
                       #print(spl)
                       break
            #print(lines[i])
            spl[2] = hexx
            #lines[i] = joinLine(spl)    
            lines[i] = ' '.join(spl) + '\n'
            
            
        elif (lines[i][10:27] == 'BREAKNECK_BLITZ_P'):
            #print("hit")
            prevHex = int(lines[i-2].split(' ')[2],16)
            hexx = hex(prevHex+1).upper().replace('X','x')
            lines[i-1] = '.equ '+moveName + ', ' + hexx+'\n\n'
            added = True
            
            hexx = hex(int(hexx,16) +1).upper().replace('X','x')
            spl = lines[i].split(' ')
            spl[2] = hexx
            lines[i] = " ".join(spl) +'\n'
            

        #elif (lines[i][0:24] == '#define NON_Z_MOVE_COUNT'):
        #    lines[i] = '#define NON_Z_MOVE_COUNT   ('+name+ ' + 1)\n'
            
    with open(directory+'\\asm_defines.s', 'w', encoding='utf-8') as file:
        file.writelines(lines)
    

if __name__=="__main__":
    path = os.getcwd()
    print(path)
    name = addMoveH(path+'\\include\\constants')
    #ddMoveASM(path,name)
    
        
            
