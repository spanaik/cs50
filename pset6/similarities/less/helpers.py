from nltk.tokenize import sent_tokenize

def lines(a, b):
    """Return lines in both a and b"""

    return list(set(a.splitlines()).intersection(b.splitlines()))


def sentences(a, b):
    """Return sentences in both a and b"""

    return list(set(sent_tokenize(a)).intersection(sent_tokenize(b)))

def substrings(a, b, n):

    a_list =[a[x:x+n] for x in range(len(a) - n + 1)]
    b_list =[b[x:x+n] for x in range(len(b) - n + 1)]

    return list(set(a_list).intersection(b_list))