EDGEHTML!CAttrArray::Destroy:
6175024f 8bff            mov     edi,edi
61750251 55              push    ebp
61750252 8bec            mov     ebp,esp
61750254 83e4f8          and     esp,0FFFFFFF8h
61750257 83ec2c          sub     esp,2Ch
6175025a 8b510c          mov     edx,dword ptr [ecx+0Ch]
6175025d 8bc2            mov     eax,edx
6175025f 53              push    ebx
61750260 d1e8            shr     eax,1
61750262 894c240c        mov     dword ptr [esp+0Ch],ecx
61750266 56              push    esi
61750267 57              push    edi
61750268 a801            test    al,1
6175026a 0f85b56f3600    jne     EDGEHTML!CAttrArray::Destroy+0x366fd6 (61ab7225)
{
  61ab7225 cc              int     3
  61ab7226 e94590c9ff      jmp     EDGEHTML!CAttrArray::Destroy+0x21 (61750270)
}
61750270 8b5d08          mov     ebx,dword ptr [ebp+8]
61750273 8d7c2428        lea     edi,[esp+28h]
61750277 c1e304          shl     ebx,4
6175027a 035908          add     ebx,dword ptr [ecx+8]
6175027d 8bf3            mov     esi,ebx
6175027f 803b04          cmp     byte ptr [ebx],4
61750282 a5              movs    dword ptr es:[edi],dword ptr [esi]
61750283 a5              movs    dword ptr es:[edi],dword ptr [esi]
61750284 a5              movs    dword ptr es:[edi],dword ptr [esi]
61750285 a5              movs    dword ptr es:[edi],dword ptr [esi]
61750286 752d            jne     EDGEHTML!CAttrArray::Destroy+0x66 (617502b5)
{                                                                                       
  617502b5 8bcb            mov     ecx,ebx                                      
  617502b7 e870e4ffff      call    EDGEHTML!CAttrValue::GetDISPID (6174e72c)    
  617502bc 8b742414        mov     esi,dword ptr [esp+14h]                      
  617502c0 8bca            mov     ecx,edx                                      
  617502c2 c1e004          shl     eax,4                                        
  617502c5 83e20f          and     edx,0Fh                                      
  617502c8 2bc8            sub     ecx,eax                                      
  617502ca 83e1f0          and     ecx,0FFFFFFF0h                               
  617502cd 0bca            or      ecx,edx                                      
  617502cf 894e0c          mov     dword ptr [esi+0Ch],ecx                      
  617502d2 0fb74302        movzx   eax,word ptr [ebx+2]                         
  617502d6 a808            test    al,8                                         
  617502d8 752c            jne     EDGEHTML!CAttrArray::Destroy+0xb7 (61750306) 
  {                                                                             
    617502da 8b560c          mov     edx,dword ptr [esi+0Ch]                      <---------- -.
    617502dd f6c208          test    dl,8                                                      |
    617502e0 0f95c1          setne   cl                                                        |
    617502e3 f6430201        test    byte ptr [ebx+2],1         // reuse                       |
    617502e7 0f95c0          setne   al                                                        |
    617502ea 84c8            test    al,cl                                                     |
    617502ec 8bce            mov     ecx,esi                                                   |
    617502ee 7498            je      EDGEHTML!CAttrArray::Destroy+0x39 (61750288) ---,         |
    617502f0 b301            mov     bl,1                                            |         |
    617502f2 eb96            jmp     EDGEHTML!CAttrArray::Destroy+0x3b (6175028a) -- | -.      |
  }                                                                                  |  |      |
  61750306 803b09          cmp     byte ptr [ebx],9                                  |  |      |
  61750309 74cf            je      EDGEHTML!CAttrArray::Destroy+0x8b (617502da)   -- |  | ----'|
  6175030b 8d442418        lea     eax,[esp+18h]                                     |  |      |
  6175030f 8bcb            mov     ecx,ebx                                           |  |      |
  61750311 50              push    eax                                               |  |      |
  61750312 e89efeffff      call    EDGEHTML!CAttrValue::GetAsVariantNC (617501b5)    |  |      |
  61750317 0fb74b02        movzx   ecx,word ptr [ebx+2]                              |  |      |
  6175031b 81e1efff0000    and     ecx,0FFEFh                                        |  |      |
  61750321 f6430380        test    byte ptr [ebx+3],80h                              |  |      |
  61750325 7526            jne     EDGEHTML!CAttrArray::Destroy+0xfe (6175034d)      |  |      |
  {                                                                                  |  |      |
    6175034d 33c0            xor     eax,eax                                         |  |      |
    6175034f ebd9            jmp     EDGEHTML!CAttrArray::Destroy+0xdb (6175032a)    |  |      |
  } else {                                                                           |  |      |
    61750327 8b4304          mov     eax,dword ptr [ebx+4]                           |  |      |
  }                                                                                  |  |      |
  6175032a 6a01            push    1                                                 |  |      |
  6175032c 6a01            push    1                                                 |  |      |
  6175032e 51              push    ecx                                               |  |      |
  6175032f 6a09            push    9                                                 |  |      |
  61750331 8d4c2428        lea     ecx,[esp+28h]                                     |  |      |
  61750335 51              push    ecx                                               |  |      |
  61750336 50              push    eax                                               |  |      |
  61750337 8bcb            mov     ecx,ebx                                           |  |      |
  61750339 e8eee3ffff      call    EDGEHTML!CAttrValue::GetDISPID (6174e72c)         |  |      |
  6175033e 50              push    eax                                               |  |      |
  6175033f 8d44242f        lea     eax,[esp+2Fh]                                     |  |      |
  61750343 8bce            mov     ecx,esi                                           |  |      |
  61750345 50              push    eax                                               |  |      |
  61750346 e8258a0800      call    EDGEHTML!CAttrArray::Set (617d8d70)    // free    |  |      |
  6175034b eb8d            jmp     EDGEHTML!CAttrArray::Destroy+0x8b (617502da)  --- |  | -----'
}                                                                                    |  |
61750288 33db            xor     ebx,ebx                                         <---'  |
6175028a d1ea            shr     edx,1                                           <------'
6175028c f6c201          test    dl,1                                                    
6175028f 0f85966f3600    jne     EDGEHTML!CAttrArray::Destroy+0x366fdc (61ab722b)
{                                                                                
  61ab722b cc              int     3                                             
  61ab722c e96490c9ff      jmp     EDGEHTML!CAttrArray::Destroy+0x46 (61750295)  
}                                                                                
61750295 ff7508          push    dword ptr [ebp+8]                                  
61750298 6a10            push    10h                                                
6175029a e8b1e01400      call    EDGEHTML!CImplAry::Delete (6189e350)               
6175029f 8d4c2428        lea     ecx,[esp+28h]                                      
617502a3 e8ae000000      call    EDGEHTML!CAttrValue::Free (61750356)               
617502a8 84db            test    bl,bl                                              
617502aa 7548            jne     EDGEHTML!CAttrArray::Destroy+0xa5 (617502f4)       
{                                                                                   
  617502f4 8b4c2414        mov     ecx,dword ptr [esp+14h]                          
  617502f8 6a03            push    3                                                
  617502fa 68eb030180      push    800103EBh                                        
  617502ff e8ac3e0c00      call    EDGEHTML!CAttrArray::DeleteAttribute (618141b0)  
  61750304 eba6            jmp     EDGEHTML!CAttrArray::Destroy+0x5d (617502ac)     
}                                                                                   
617502ac 5f              pop     edi                                                
617502ad 5e              pop     esi                                                
617502ae 5b              pop     ebx                                                
617502af 8be5            mov     esp,ebp                                            
617502b1 5d              pop     ebp                                                
617502b2 c20400          ret     4                                                  

