MSHTML!Method_VARIANTBOOLp_BSTR_o0oVARIANT:                                                                             args {
                                                                                                                          00 ebp+08 DWORD dwArg08
                                                                                                                          04 ebp+0C DWORD dwArg0C
                                                                                                                          08 ebp+10 DWORD dwArg10
                                                                                                                          0C ebp+14 DWORD dwArg14
                                                                                                                          10 ebp+18 Unknown* poArg18
                                                                                                                          14 ebp+1C DWORD dwArg1C
                                                                                                                          18 ebp+20 DWORD dwArg20
                                                                                                                          1C ebp+24 DWORD poArg24
                                                                                                                        }
                                                                                                                        vars = {                    
void VariantInit(                                                                                                         00 DWORD dwVar00   (0)
  _Out_ VARIANTARG *pvarg                                                                                                 04 DWORD dwVar04   (0)
);                                                                                                                        08 WORD wVar08     (8)
// The VariantInit function initializes the VARIANTARG by setting the vt field to VT_EMPTY.                               0A WORD wVar0A     (C)
// Unlike VariantClear, this function does not interpret the current contents of the VARIANTARG.                          0C VARIANT vVar0C {       
// Use VariantInit to initialize new local variables of type VARIANTARG (or VARIANT).                                       0C WORD vt              
                                                                                                                            0E WORD wReserved1      
MSHTML!Method_VARIANTBOOLp_BSTR_o0oVARIANT:                                                                                 10 WORD wReserved2      
69895410 8bff            mov     edi,edi                                                                                    12 WORD wReserved3      
69895412 55              push    ebp                                                                                        14 QWORD qwData         
69895413 8bec            mov     ebp,esp                                                                                  }                         
69895415 83e4f8          and     esp,0FFFFFFF8h                                                                         }         
69895418 83ec1c          sub     esp,1Ch                                                                                esp = &vars
6989541b 83242400        and     dword ptr [esp],0                                                                      dwVar00 = 0
6989541f 53              push    ebx                                                                                    esp = &vars-04
69895420 56              push    esi                                                                                    esp = &vars-08
69895421 57              push    edi                                                                                    esp = &vars-0C
69895422 6a08            push    8                                                                                      
69895424 58              pop     eax                                                                                    eax = 8
69895425 6a0c            push    0Ch                                                                                    esp = &vars-10
69895427 6689442418      mov     word ptr [esp+18h],ax                                                                  WORD wVar08 = 8 (&vars-10+18)
6989542c 58              pop     eax                                                                                    eax = C, esp = &vars-0C
6989542d 6689442416      mov     word ptr [esp+16h],ax                                                                  WORD wVar0A = C (&vars-0C+16)
69895432 8d442418        lea     eax,[esp+18h]                                                                          VARIANT* eax = &vVar0C (&vars-0C+18)
69895436 50              push    eax                                                                                    esp = &vars-10
69895437 ff15d449fd69    call    dword ptr [MSHTML!_imp__VariantInit (69fd49d4)]                                        VariantInit(&vVar0C), esp = &vars-0C
6989543d 6a0a            push    0Ah                                                                                    
6989543f 58              pop     eax                                                                                    eax = 0A
69895440 8364241000      and     dword ptr [esp+10h],0                                                                  dwVar04 = 0 (&vars-0C+10)
69895445 6689442418      mov     word ptr [esp+18h],ax                                                                  vVar0C.vt = VT_ERROR (&vars-0C+18 = 0C)
6989544a 8d442418        lea     eax,[esp+18h]                                                                          eax = &vVar0C.vt;
6989544e 6aff            push    0FFFFFFFFh                                                                             >> -1, esp = &vars-10
69895450 50              push    eax                                                                                    >> &vVar0C.vt, esp = &vars-14
69895451 8d442414        lea     eax,[esp+14h]                                                                          eax = &dwVar00 (&vars-14+14)
69895455 50              push    eax                                                                                    >> &dwVar00, esp = &vars-18
69895456 8d442420        lea     eax,[esp+20h]                                                                          eax = &wVar08 (&vars-18+20)
6989545a 50              push    eax                                                                                    >> &wVar08, esp = &vars-1C
6989545b 8b4518          mov     eax,dword ptr [ebp+18h]                                                                eax = dwArg18
6989545e ff7028          push    dword ptr [eax+28h]                                                                    >> poArg10->dwProp28, esp = &vars-20
69895461 8d442424        lea     eax,[esp+24h]                                                                          eax = &dwVar04 (&vars-20+24)
69895465 50              push    eax                                                                                    >> &dwVar04, esp = &vars-24
69895466 ff7520          push    dword ptr [ebp+20h]                                                                    >> dwArg20, esp = &vars-28
69895469 ff750c          push    dword ptr [ebp+0Ch]                                                                    >> dwArg0C, esp = &vars-2C
6989546c e813e070ff      call    MSHTML!DispParamsToCParams (68fa3484)                                                  esi = DispParamsToCParams(dwArg0c, dwArg20, poArg18->dwProp28, &wVar08, &dwVar00, &vVar0C.vt)
69895471 8bf0            mov     esi,eax                                                                                
69895473 83c420          add     esp,20h                                                                                esp = &vars-0C
69895476 85f6            test    esi,esi                                                                                
69895478 7414            je      l1 (6989548e)                                                                          if (esi) {
{                                                                                                                         // handle failure/error
  6989547a 0f89a2000000    jns     l2 (69895522)                                                                        
  {                                                                                                                     
    69895480 8b4d08          mov     ecx,dword ptr [ebp+8]                                                              
    69895483 56              push    esi                                                                                
    69895484 e82bb77bff      call    MSHTML!CBase::WriteErrorInfo (69050bb4)                                            
    69895489 e994000000      jmp     l2 (69895522)                                                                      
  }                                                                                                                     
} else {                                                                                                                } else {
  l1:                                                                                                                   
  6989548e f705808fea6900020000 test dword ptr [MSHTML!Microsoft_IEEnableBits (69ea8f80)],200h                          if (something) {
  69895498 741b            je      l3 (698954b5)                                                                          // bla bla bla
  {                                                                                                                     
    6989549a 8b5514          mov     edx,dword ptr [ebp+14h]                                                            
    6989549d b928c45869      mov     ecx,offset MSHTML!MSHTML_DOM_MARSHALLING_NATIVE_START (6958c428)                   
    698954a2 6a04            push    4                                                                                  
    698954a4 ff35fce5eb69    push    dword ptr [MSHTML!Microsoft_IEHandle+0x4 (69ebe5fc)]                               
    698954aa ff35f8e5eb69    push    dword ptr [MSHTML!Microsoft_IEHandle (69ebe5f8)]                                   
    698954b0 e89408edff      call    MSHTML!Template_pq (69765d49)                                                      
  }                                                                                                                     
  l3:                                                                                                                   }
  698954b5 8b4524          mov     eax,dword ptr [ebp+24h]                                                              eax = poArg24
  698954b8 8d742418        lea     esi,[esp+18h]                                                                        esi = &vVar0C (&vars-0C+18)
  698954bc 8bdc            mov     ebx,esp                                                                              ebx = &vars-0C // save current stack pointer
  698954be 83c008          add     eax,8                                                                                eax = &(poArg24->dwProp08)
  698954c1 50              push    eax                                                                                  >> &(poArg24->dwProp08), esp = &vars-10
  698954c2 8b4514          mov     eax,dword ptr [ebp+14h]                                                              eax = dwArg14
  698954c5 83ec10          sub     esp,10h                                                                              VARIANT vVarTemp, esp = &vars-20
  698954c8 8bfc            mov     edi,esp                                                                              edi = vVarTemp
  698954ca ff742420        push    dword ptr [esp+20h]                                                                  >> dwVar00, esp = &vars-24
  698954ce a5              movs    dword ptr es:[edi],dword ptr [esi]                                                   vVarTemp = vVar0C
  698954cf ff7510          push    dword ptr [ebp+10h]                                                                  >> dwArg10, esp = &vars-28
  698954d2 a5              movs    dword ptr es:[edi],dword ptr [esi]                                                   (vVarTemp = vVar0C)
  698954d3 a5              movs    dword ptr es:[edi],dword ptr [esi]                                                   (vVarTemp = vVar0C)
  698954d4 a5              movs    dword ptr es:[edi],dword ptr [esi]                                                   (vVarTemp = vVar0C)
  698954d5 8b30            mov     esi,dword ptr [eax]                                                                  esi = poArg24->dwProp08
  698954d7 8bce            mov     ecx,esi                                                                              ecx = poArg24->dwProp08
  698954d9 ff159ceffc69    call    dword ptr [MSHTML!__guard_check_icall_fptr (69fcef9c)]                               
  698954df ffd6            call    esi                                                                                  poArg24->dwProp08(dwArg10, dwVar00, &(poArg24->dwProp08))
  698954e1 3bdc            cmp     ebx,esp                                                                              
  698954e3 7407            je      l4 (698954ec)                                                                        
  {                                                                                                                     
    698954e5 b904000000      mov     ecx,4                                                                              
    698954ea cd29            int     29h                                                                                
  }                                                                                                                     
  l4:                                                                                                                   
  698954ec f705808fea6900020000 test dword ptr [MSHTML!Microsoft_IEEnableBits (69ea8f80)],200h                          
  698954f6 8bf0            mov     esi,eax                                                                              
  698954f8 741b            je      l5 (69895515)                                                                        
  {                                                                                                                     
    698954fa 8b5510          mov     edx,dword ptr [ebp+10h]                                                            
    698954fd b918c45869      mov     ecx,offset MSHTML!MSHTML_DOM_MARSHALLING_NATIVE_STOP (6958c418)                    
    69895502 6a02            push    2                                                                                  
    69895504 ff35fce5eb69    push    dword ptr [MSHTML!Microsoft_IEHandle+0x4 (69ebe5fc)]                               
    6989550a ff35f8e5eb69    push    dword ptr [MSHTML!Microsoft_IEHandle (69ebe5f8)]                                   
    69895510 e83408edff      call    MSHTML!Template_pq (69765d49)                                                      
  }                                                                                                                     
  l5:                                                                                                                   
  69895515 85f6            test    esi,esi                                                                              
  69895517 7509            jne     l2 (69895522)                                                                        
  69895519 8b4524          mov     eax,dword ptr [ebp+24h]                                                              
  6989551c 6a0b            push    0Bh                                                                                  
  6989551e 59              pop     ecx                                                                                  
  6989551f 668908          mov     word ptr [eax],cx                                                                    
}                                                                                                                       
l2:                                                                                                                     
69895522 f644241001      test    byte ptr [esp+10h],1                                                                   
69895527 7411            je      l6 (6989553a)                                                                          
  {                                                                                                                     
  69895529 837c240c00      cmp     dword ptr [esp+0Ch],0                                                                
  6989552e 740a            je      l6 (6989553a)                                                                        
    {                                                                                                                   
    69895530 ff74240c        push    dword ptr [esp+0Ch]                                                                
    69895534 ff15c049fd69    call    dword ptr [MSHTML!_imp__SysFreeString (69fd49c0)]                                  
    }                                                                                                                   
  }                                                                                                                     
l6:                                                                                                                     
6989553a f644241002      test    byte ptr [esp+10h],2                                                                   
6989553f 740b            je      l7 (6989554c)                                                                          
{                                                                                                                       
  69895541 8d442418        lea     eax,[esp+18h]                                                                        
  69895545 50              push    eax                                                                                  
  69895546 ff159849fd69    call    dword ptr [MSHTML!_imp__VariantClear (69fd4998)]                                     
}                                                                                                                       
l7:                                                                                                                     
6989554c 5f              pop     edi                                                                                    
6989554d 8bc6            mov     eax,esi                                                                                
6989554f 5e              pop     esi                                                                                    
69895550 5b              pop     ebx                                                                                    
69895551 8be5            mov     esp,ebp                                                                                
69895553 5d              pop     ebp                                                                                    
69895554 c22000          ret     20h                                                                                    