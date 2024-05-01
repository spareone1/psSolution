N, M, K = input().split()

N=int(N)
M=int(M)
K=int(K)

if N<1 :
    print ("잘못된 값입니다.")

if N>1000000 :
    print ("잘못된 값입니다.")    
  
if M<0 :
    print ("잘못된 값입니다.")

if K>N :
    print ("잘못된 값입니다.")

if K==M :
    print (str(N))

if K<M :
    s=K+N-M
    print (str(s))
if K>M :
    s=M+N-K
    print (str(s))
