def convert_ASCII(texte):
    return [ord(char) for char in texte]

def convert_CHAR(ascii_list):
    return ''.join(chr(code) for code in ascii_list)

# info -> nskt avec un décalage de 5.

'''
def chiffre_Cesar(texte,key):
    newText = ''
    for code in texte:
        newText += convert_CHAR([convert_ASCII(code)[0] + key])
    return newText

def dechiffre_Cesar(texte,key):
    newText = ''
    for code in texte:
        newText += convert_CHAR([convert_ASCII(code)[0] - key])
    return newText

print(chiffre_Cesar("Bonjour", 5))
print(dechiffre_Cesar("Gtsotzw", 5))
'''

def chiffre_Cesar(texte, key):
    return [(char + key - 65) % 26 + 65 if 'A' <= chr(char) <= 'Z' else
            (char + key - 97) % 26 + 97 if 'a' <= chr(char) <= 'z' else char
            for char in texte]

def dechiffre_Cesar(texte, key):
    return [(char - key - 65) % 26 + 65 if 'A' <= chr(char) <= 'Z' else
            (char - key - 97) % 26 + 97 if 'a' <= chr(char) <= 'z' else char
            for char in texte]

def frequence(texte):
    # Initialize a dictionary to count occurrences
    freq_dict = {}
    for char in texte:
        if char in freq_dict:
            freq_dict[char] += 1
        else:
            freq_dict[char] = 1
    # Convert dictionary to a list of tuples [(ASCII code, frequency), ...]
    return [(ord(char), count) for char, count in freq_dict.items()]

'''
def cryptanalyse(cipher):
    # Convert cipher text to ASCII codes
    cipher_ascii = convert_ASCII(cipher)
    
    freq_list = frequence(cipher)
    most_common = max(freq_list, key=lambda x: x[1])[0]
    
    key = (most_common - ord('e')) % 26
    
    decrypted_ascii = dechiffre_Cesar(cipher_ascii, key)
    
    # Convert ASCII codes back to string
    return convert_CHAR(decrypted_ascii)
'''
def cryptanalyse(cipher):
    # Convert cipher text to a list of ASCII values
    cipher_ascii = [ord(char) for char in cipher]
    # Find the most frequent character
    freq_list = frequence(cipher)
    most_common = max(freq_list, key=lambda x: x[1])[0]  # Get the ASCII code of the most common character
    # Assume the most common letter corresponds to 'e' in English
    key = (most_common - ord('e')) % 26
    # Decrypt the cipher using the guessed key
    return convert_CHAR(dechiffre_Cesar(cipher_ascii, key))


cipher = "V'muyq nqmgoagb xqe bayyqe qf xqe dagfqe pqbmdfqyqzfmxqe!"
cipher = "[ol'yhiip{4ovsl'~lu{'z{yhpno{'vu'sprl'h'{|uuls'mvy'zvtl'~h\x803'huk'{olu'kpwwlk'z|kklus\x80'kv~u3'zv'z|kklus\x803'{oh{'Hspjl'ohk'uv{'h'tvtlu{'{v'{opur'hiv|{'z{vwwpun'olyzlsm3'ilmvyl'zol'mv|uk'olyzlsm'mhsspun'kv~u'~oh{'zlltlk'h'kllw'~lss5'Lp{oly'{ol'~lss'~hz'}ly\x80'kllw3'vy'zol'mlss'}ly\x80'zsv~s\x803'mvy'zol'ohk'wslu{\x80'vm'{ptl'hz'zol'~lu{'kv~u'{v'svvr'hiv|{'oly3'huk'{v'~vukly'~oh{'~v|sk'ohwwlu'ul\x7f{5'Mpyz{3'zol'{yplk'{v'svvr'kv~u'huk'thrl'v|{'~oh{'zol'~hz'jvtpun'{v3'i|{'p{'~hz'{vv'khyr'{v'zll'hu\x80{opunA'{olu3'zol'svvrlk'h{'{ol'zpklz'vm'{ol'~lss3'huk'uv{pjlk'{oh{'{ol\x80'~lyl'mpsslk'~p{o'j|wivhykz'huk'ivvr4zols}lzB'olyl'huk'{olyl'~lyl'thwz'huk'wpj{|ylz'o|un'vu'wlnz5'Zol'{vvr'h'qhy'kv~u'vmm'vul'vm'{ol'zols}lz'hz'zol'whzzlkA'p{'~hz'shilsslk')Vyhunl'Thythshkl3)'i|{'{v'oly'nylh{'kpzhwwvpu{tlu{'p{'~hz'ltw{\x80A'zol'kpk'uv{'sprl'{v'kyvw'{ol'qhy3'mvy'mlhy'vm'rpsspun'zvtlivk\x80'|uklyulh{o3'zv'thuhnlk'{v'w|{'p{'pu{v'vul'vm'{ol'j|wivhykz'hz'zol'mlss'whz{'p{5)^lss()'{ov|no{'Hspjl'{v'olyzlsm3')hm{ly'z|jo'h'mhss'hz'{opz3'P'zohss'{opur'uv{opun'vm'{|tispun'kv~u'z{hpyz('Ov~'iyh}l'{ol\x80.ss'hss'{opur'tl'h{'ovtl('^o\x803'P'~v|sku.{'zh\x80'hu\x80{opun'hiv|{'p{3'l}lu'pm'P'mlss'vmm'{ol'{vw'vm'{ol'ov|zl()'/~opjo'~hz'tvz{'sprls\x80'{y|l505'Kv~u3'kv~u3'kv~u5'^v|sk'{ol'mhss'ul}ly'jvtl'{v'hu'lukF')P'~vukly'ov~'thu\x80'tpslz'P.}l'mhsslu'i\x80'{opz'{ptlF)'zhpk'zol'hsv|k3')P't|z{'il'nl{{pun'zvtl~olyl'ulhy'{ol'jlu{yl'vm'{ol'lhy{o5'Sl{'tl'zllA'{oh{'~v|sk'il'mv|y'{ov|zhuk'tpslz'kv~u3'P'{opur\xe9\x87\x9b)'/mvy'\x80v|'zll'Hspjl'ohk'slhyu{'zl}lyhs'{opunz'vm'{opz'zvy{'pu'oly'slzzvuz'pu'{ol'zjovvsyvvt3'huk'{ov|no'{opz'~hz'uv{'h'}ly\x80'nvvk'vwwvy{|up{\x80'vm'zov~pun'vmm'oly'ruv~slknl3'hz'{olyl'~hz'uv'vul'{v'olhy'oly3'z{pss'p{'~hz'nvvk'wyhj{pjl'{v'zh\x80'p{'v}ly30')\x80lz3'{oh{.z'{ol'ypno{'kpz{hujl3'i|{'{olu'P'~vukly'~oh{'Svunp{|kl'vy'Sh{p{|kl4spul'zohss'P'il'puF)'/Hspjl'ohk'uv'pklh'~oh{'Svunp{|kl'~hz3'vy'Sh{p{|kl'lp{oly3'i|{'zol'{ov|no{'{ol\x80'~lyl'upjl'nyhuk'~vykz'{v'zh\x8050"

print(cryptanalyse(cipher))