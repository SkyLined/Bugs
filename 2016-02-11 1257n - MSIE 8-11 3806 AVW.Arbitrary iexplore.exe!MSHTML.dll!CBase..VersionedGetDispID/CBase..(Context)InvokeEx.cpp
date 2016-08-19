MSHTML!CBase::InvokeEx:
6a638960 8bff            mov     edi,edi
6a638962 55              push    ebp
6a638963 8bec            mov     ebp,esp
6a638965 8b4d08          mov     ecx,dword ptr [ebp+8]                          @ecx = arg1
6a638968 8b550c          mov     edx,dword ptr [ebp+0Ch]                        @edx = arg2
6a63896b 51              push    ecx                                            
6a63896c ff7524          push    dword ptr [ebp+24h]                            
6a63896f ff7520          push    dword ptr [ebp+20h]
6a638972 ff751c          push    dword ptr [ebp+1Ch]
6a638975 ff7518          push    dword ptr [ebp+18h]
6a638978 ff7514          push    dword ptr [ebp+14h]
6a63897b ff7510          push    dword ptr [ebp+10h]                            
6a63897e e8c1e7e4ff      call    MSHTML!CBase::ContextInvokeEx (6a487144)       CBase::ContextInvokeEx(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg1)
6a638983 5d              pop     ebp
6a638984 c22000          ret     20h



MSHTML!CBase::ContextInvokeEx:                                                  @ebp = arguments {
                                                                                  ecx DWORD dwArgCX
                                                                                  edx DWORD dwArgDX
                                                                                  +08 DWORD dwArg08
                                                                                  +0C DWORD dwArg0C
                                                                                  +10 DWORD dwArg10
                                                                                  +14 DWORD dwArg14
                                                                                  +18 DWORD dwArg18
                                                                                  +1C DWORD dwArg1C
                                                                                  +24 DWORD dwArg24
                                                                                  +28 DWORD dwArg28
                                                                                  +2C DWORD dwArg2C
                                                                                }
6a487144 8bff            mov     edi,edi
6a487146 55              push    ebp
6a487147 8bec            mov     ebp,esp
6a487149 83e4f8          and     esp,0FFFFFFF8h
6a48714c 83ec5c          sub     esp,5Ch                                        esp = locals {
                                                                                  +5C DWORD dwVar5C
                                                                                  +58 DWORD dwVar58
                                                                                  +54 DWORD dwVar54
                                                                                  +50 DWORD dwVar50
                                                                                  +4C DWORD dwVar4C
                                                                                  +48 DWORD dwVar48
                                                                                  +44 DWORD dwVar44
                                                                                  +40 DWORD dwVar40
                                                                                  +3C DWORD dwVar3C
                                                                                  +38 DWORD dwVar38
                                                                                  +34 DWORD dwVar34
                                                                                  +30 DWORD dwVar30
                                                                                  +2C DWORD dwVar2C
                                                                                  +28 DWORD dwVar28
                                                                                  +24 DWORD dwVar24
                                                                                  +20 DWORD dwVar20
                                                                                  +1C DWORD dwVar1C
                                                                                  +18 DWORD dwVar18
                                                                                  +14 DWORD dwVar14
                                                                                  +10 DWORD dwVar10
                                                                                  +0C DWORD dwVar0C
                                                                                  +08 DWORD dwVar08
                                                                                  +04 DWORD dwVar04
                                                                                  +03 BYTE bVar03
                                                                                  +02 BYTE bVar02
                                                                                  +01 BYTE bVar01
                                                                                  +00 BYTE bVar00
                                                                                }
6a48714f a0813d326b      mov     al,byte ptr [MSHTML!g_FeatureControlHelper+0x1 (6b323d81)]
6a487154 53              push    ebx                                            esp = locals-04
6a487155 56              push    esi                                            esp = locals-08
6a487156 57              push    edi                                            esp = locals-0C
6a487157 33db            xor     ebx,ebx                                        ebx = 0
6a487159 8954242c        mov     dword ptr [esp+2Ch],edx                        dwVar20 = dwArgDX
6a48715d 885c240f        mov     byte ptr [esp+0Fh],bl                          bVar03 = 0
6a487161 8bf9            mov     edi,ecx                                        edi = dwArgCX
6a487163 897c241c        mov     dword ptr [esp+1Ch],edi                        dwVar10 = dwArgCX
6a487167 a808            test    al,8                                           if (MSHTML!g_FeatureControlHelper & 0x800) {
6a487169 0f85459f2900    jne     MSHTML!CBase::ContextInvokeEx+0x5ef (6a7210b4)

  MSHTML!CBase::ContextInvokeEx+0x5ef:                                          
  6a7210b4 6a02            push    2                                            >> 2, esp = locals-10
  6a7210b6 53              push    ebx                                          >> 0, esp = locals-14
  6a7210b7 ff155446456b    call    dword ptr [MSHTML!_imp__CoInternetIsFeatureEnabled (6b454654)]
                                                                                eax = urlmon!CoInternetIsFeatureEnabled(FEATURE_OBJECT_CACHING, GET_FEATURE_FROM_PROCESS)
                                                                                // Check whether to block access to objects instantiated and cached in one domain from another domain.
  6a7210bd 33c9            xor     ecx,ecx                                      
  6a7210bf 41              inc     ecx                                          
  6a7210c0 3bc1            cmp     eax,ecx                                      if (eax) { // do origin checks
  6a7210c2 0f85b760d6ff    jne     MSHTML!CBase::ContextInvokeEx+0x37 (6a48717f)
  6a7210c8 e9ded31900      jmp     MSHTML!CBase::ContextInvokeEx+0x603 (6a8be4ab)
  
  MSHTML!CBase::ContextInvokeEx+0x603:
  6a8be4ab 8ac3            mov     al,bl                                          al = 0
  6a8be4ad e9c58cbcff      jmp     MSHTML!CBase::ContextInvokeEx+0x33 (6a487177)
                                                                                }

6a48716f 33c9            xor     ecx,ecx
6a487171 c0e804          shr     al,4
6a487174 41              inc     ecx
6a487175 22c1            and     al,cl
6a487177 84c0            test    al,al
6a487179 0f8487000000    je      MSHTML!CBase::ContextInvokeEx+0x9f (6a487206)
  6a48717f 8b07            mov     eax,dword ptr [edi]
  6a487181 89442440        mov     dword ptr [esp+40h],eax
  6a487185 817848d059ae6a  cmp     dword ptr [eax+48h],offset MSHTML!__vtguard (6aae59d0)
  6a48718c 0f85ac744300    jne     MSHTML!CBase::ContextInvokeEx+0xc07 (6a8be63e)
  
    MSHTML!CBase::ContextInvokeEx+0xc07:
    6a8be63e 51              push    ecx
    6a8be63f e8183c2200      call    MSHTML!__report_securityfailure (6aae225c)
    6a8be644 bb03000280      mov     ebx,80020003h
    6a8be649 e98796bcff      jmp     MSHTML!CBase::ContextInvokeEx+0x92e (6a487cd5)
    
    MSHTML!CBase::ContextInvokeEx+0x92e:
    6a487cd5 8b442430        mov     eax,dword ptr [esp+30h]
    6a487cd9 8bfc            mov     edi,esp
    6a487cdb 50              push    eax
    6a487cdc 8b08            mov     ecx,dword ptr [eax]
    6a487cde 8b7108          mov     esi,dword ptr [ecx+8]
    6a487ce1 8bce            mov     ecx,esi
    6a487ce3 ff159cef446b    call    dword ptr [MSHTML!__guard_check_icall_fptr (6b44ef9c)]
    6a487ce9 ffd6            call    esi
    6a487ceb 3bfc            cmp     edi,esp
    6a487ced 0f858c684300    jne     MSHTML!CBase::ContextInvokeEx+0x948 (6a8be57f)
    
      MSHTML!CBase::ContextInvokeEx+0x948:
      6a8be57f b904000000      mov     ecx,4
      6a8be584 cd29            int     29h
      6a8be586 e96897bcff      jmp     MSHTML!CBase::ContextInvokeEx+0x94f (6a487cf3)
    
    6a487cf3 8d442458        lea     eax,[esp+58h]
    6a487cf7 50              push    eax
    6a487cf8 ff159849456b    call    dword ptr [MSHTML!_imp__VariantClear (6b454998)]
    6a487cfe e9b6f7ffff      jmp     MSHTML!CBase::ContextInvokeEx+0x3bf (6a4874b9)

  6a487192 e946714300      jmp     MSHTML!CBase::ContextInvokeEx+0x4a (6a8be2dd)
  6a487197 8bf0            mov     esi,eax
  6a487199 85f6            test    esi,esi
  6a48719b 0f8587714300    jne     MSHTML!CBase::ContextInvokeEx+0x96 (6a8be328)
  6a4871a1 e9d75c5000      jmp     MSHTML!`CBackgroundInfo::Property<CBackgroundImage>'::`7'::`dynamic atexit destructor for 'fieldDefaultValue''+0xf6e5e (6a98ce7d)
  6a4871a6 85c0            test    eax,eax
  6a4871a8 0f84a2080000    je      MSHTML!CBase::ContextInvokeEx+0xbfc (6a487a50)
  6a4871ae 8b7014          mov     esi,dword ptr [eax+14h]
  6a4871b1 85f6            test    esi,esi
  6a4871b3 7412            je      MSHTML!CBase::ContextInvokeEx+0x4f3 (6a4871c7)
  6a4871b5 399e74030000    cmp     dword ptr [esi+374h],ebx
  6a4871bb 0f84b4575000    je      MSHTML!`CBackgroundInfo::Property<CBackgroundImage>'::`7'::`dynamic atexit destructor for 'fieldDefaultValue''+0xf6956 (6a98c975)
  6a4871c1 8b9e74030000    mov     ebx,dword ptr [esi+374h]
  6a4871c7 33c9            xor     ecx,ecx
  6a4871c9 41              inc     ecx
  6a4871ca 85db            test    ebx,ebx
  6a4871cc 7409            je      MSHTML!CBase::ContextInvokeEx+0x503 (6a4871d7)
  6a4871ce 844b28          test    byte ptr [ebx+28h],cl
  6a4871d1 0f85c5575000    jne     MSHTML!`CBackgroundInfo::Property<CBackgroundImage>'::`7'::`dynamic atexit destructor for 'fieldDefaultValue''+0xf697d (6a98c99c)
  6a4871d7 ff751c          push    dword ptr [ebp+1Ch]
  6a4871da 8b4514          mov     eax,dword ptr [ebp+14h]
  6a4871dd ff7518          push    dword ptr [ebp+18h]
  6a4871e0 8b7510          mov     esi,dword ptr [ebp+10h]
  6a4871e3 50              push    eax
  6a4871e4 56              push    esi
  6a4871e5 ff750c          push    dword ptr [ebp+0Ch]
  6a4871e8 89442434        mov     dword ptr [esp+34h],eax
  6a4871ec ff7508          push    dword ptr [ebp+8]
  6a4871ef 8974243c        mov     dword ptr [esp+3Ch],esi
  6a4871f3 51              push    ecx
  6a4871f4 ff742448        push    dword ptr [esp+48h]
  6a4871f8 8bcf            mov     ecx,edi
  6a4871fa e8316a0900      call    MSHTML!CBase::InvokeAA (6a51dc30)
  6a4871ff 8bd8            mov     ebx,eax
  6a487201 e934080000      jmp     MSHTML!CBase::ContextInvokeEx+0x52d (6a487a3a)
6a487206 8b4c242c        mov     ecx,dword ptr [esp+2Ch]
6a48720a 8b7514          mov     esi,dword ptr [ebp+14h]
6a48720d 895c243c        mov     dword ptr [esp+3Ch],ebx
6a487211 895c2434        mov     dword ptr [esp+34h],ebx
6a487215 895c2438        mov     dword ptr [esp+38h],ebx
6a487219 89742420        mov     dword ptr [esp+20h],esi
6a48721d 81f9c0c62d00    cmp     ecx,2DC6C0h
6a487223 0f8d5b3d3100    jge     MSHTML!CBase::ContextInvokeEx+0x48c (6a79af84)
6a487229 81f9581b0180    cmp     ecx,80011B58h
6a48722f 0f832ea03000    jae     MSHTML!`CBackgroundInfo::Property<CBackgroundImage>'::`7'::`dynamic atexit destructor for 'fieldDefaultValue''+0xf692d (6a791263)
6a487235 83f9ff          cmp     ecx,0FFFFFFFFh
6a487238 0f85f8704300    jne     MSHTML!CBase::ContextInvokeEx+0xd7 (6a8be336)
6a48723e e985575000      jmp     MSHTML!`CBackgroundInfo::Property<CBackgroundImage>'::`7'::`dynamic atexit destructor for 'fieldDefaultValue''+0xf69a9 (6a98c9c8)
6a487243 8b542430        mov     edx,dword ptr [esp+30h]
6a487247 8d4c2418        lea     ecx,[esp+18h]
6a48724b 53              push    ebx
6a48724c 51              push    ecx
6a48724d 8d4c241c        lea     ecx,[esp+1Ch]
6a487251 51              push    ecx
6a487252 8d4c241c        lea     ecx,[esp+1Ch]
6a487256 51              push    ecx
6a487257 8d4c2438        lea     ecx,[esp+38h]
6a48725b 51              push    ecx
6a48725c 8b4c2440        mov     ecx,dword ptr [esp+40h]
6a487260 50              push    eax
6a487261 e85fbae7ff      call    MSHTML!CBase::FindPropDescFromDispID (6a302cc5)
6a487266 85c0            test    eax,eax
6a487268 0f8521ec3000    jne     MSHTML!CBase::ContextInvokeEx+0xada (6a795e8f)
6a48726e 8b4d0c          mov     ecx,dword ptr [ebp+0Ch]
6a487271 8d7c2448        lea     edi,[esp+48h]
6a487275 ab              stos    dword ptr es:[edi]
6a487276 33d2            xor     edx,edx
6a487278 ab              stos    dword ptr es:[edi]
6a487279 ab              stos    dword ptr es:[edi]
6a48727a ab              stos    dword ptr es:[edi]
6a48727b 8bc1            mov     eax,ecx
6a48727d 8b7c241c        mov     edi,dword ptr [esp+1Ch]
6a487281 2500800000      and     eax,8000h
6a487286 663bd0          cmp     dx,ax
6a487289 0f8513585000    jne     MSHTML!`CBackgroundInfo::Property<CBackgroundImage>'::`7'::`dynamic atexit destructor for 'fieldDefaultValue''+0xf6a83 (6a98caa2)
6a48728f 8b442428        mov     eax,dword ptr [esp+28h]
6a487293 f7401400030000  test    dword ptr [eax+14h],300h
6a48729a 7458            je      MSHTML!CBase::ContextInvokeEx+0x229 (6a4872f4)
6a48729c 8b07            mov     eax,dword ptr [edi]
6a48729e 885c240e        mov     byte ptr [esp+0Eh],bl
6a4872a2 817848d059ae6a  cmp     dword ptr [eax+48h],offset MSHTML!__vtguard (6aae59d0)
6a4872a9 0f840d714300    je      MSHTML!CBase::ContextInvokeEx+0x1c4 (6a8be3bc)
6a4872af e9a3070000      jmp     MSHTML!CBase::ContextInvokeEx+0xc03 (6a487a57)
6a4872b4 51              push    ecx
6a4872b5 e8f633ddff      call    MSHTML!PlainRelease (6a25a6b0)
6a4872ba e9d8010000      jmp     MSHTML!CBase::ContextInvokeEx+0x39d (6a487497)
6a4872bf 85c0            test    eax,eax
6a4872c1 0f8497070000    je      MSHTML!CBase::ContextInvokeEx+0xc0d (6a487a5e)
6a4872c7 8b7014          mov     esi,dword ptr [eax+14h]
6a4872ca 85f6            test    esi,esi
6a4872cc 0f848a3a2700    je      MSHTML!CBase::ContextInvokeEx+0x681 (6a6fad5c)
6a4872d2 399e74030000    cmp     dword ptr [esi+374h],ebx
6a4872d8 0f84a50a0000    je      MSHTML!CBase::ContextInvokeEx+0xb48 (6a487d83)
6a4872de 8b8674030000    mov     eax,dword ptr [esi+374h]
6a4872e4 85c0            test    eax,eax
6a4872e6 740c            je      MSHTML!CBase::ContextInvokeEx+0x229 (6a4872f4)
6a4872e8 33c9            xor     ecx,ecx
6a4872ea 41              inc     ecx
6a4872eb 844828          test    byte ptr [eax+28h],cl
6a4872ee 0f85f8565000    jne     MSHTML!`CBackgroundInfo::Property<CBackgroundImage>'::`7'::`dynamic atexit destructor for 'fieldDefaultValue''+0xf69cd (6a98c9ec)
6a4872f4 8b7510          mov     esi,dword ptr [ebp+10h]
6a4872f7 89742424        mov     dword ptr [esp+24h],esi
6a4872fb 8b5608          mov     edx,dword ptr [esi+8]
6a4872fe 8954243c        mov     dword ptr [esp+3Ch],edx
6a487302 395e0c          cmp     dword ptr [esi+0Ch],ebx
6a487305 0f85aac0f9ff    jne     MSHTML!CBase::ContextInvokeEx+0x97f (6a4233b5)
6a48730b 8b4514          mov     eax,dword ptr [ebp+14h]
6a48730e 85c0            test    eax,eax
6a487310 0f8492c0f9ff    je      MSHTML!CBase::ContextInvokeEx+0x688 (6a4233a8)
6a487316 50              push    eax
6a487317 ff15d449456b    call    dword ptr [MSHTML!_imp__VariantInit (6b4549d4)]
6a48731d 8b54243c        mov     edx,dword ptr [esp+3Ch]
6a487321 8b450c          mov     eax,dword ptr [ebp+0Ch]
6a487324 bb01400080      mov     ebx,80004001h
6a487329 8b4c2428        mov     ecx,dword ptr [esp+28h]
6a48732d 85d2            test    edx,edx
6a48732f 0f8548c0f9ff    jne     MSHTML!CBase::ContextInvokeEx+0x616 (6a42337d)
6a487335 a802            test    al,2
6a487337 0f8456c0f9ff    je      MSHTML!CBase::ContextInvokeEx+0x623 (6a423393)
6a48733d f7411400010000  test    dword ptr [ecx+14h],100h
6a487344 0f8449c0f9ff    je      MSHTML!CBase::ContextInvokeEx+0x623 (6a423393)
6a48734a f7411400020000  test    dword ptr [ecx+14h],200h
6a487351 0f85cc070000    jne     MSHTML!CBase::ContextInvokeEx+0x695 (6a487b23)
6a487357 33ff            xor     edi,edi
6a487359 8bdf            mov     ebx,edi
6a48735b 0fb74124        movzx   eax,word ptr [ecx+24h]
6a48735f 8b0485d874486a  mov     eax,dword ptr MSHTML!CBase::s_apfnIOleCommandTarget+0x14 (6a4874d8)[eax*4]
6a487366 89442444        mov     dword ptr [esp+44h],eax
6a48736a 85c0            test    eax,eax
6a48736c 0f840d052c00    je      MSHTML!CBase::ContextInvokeEx+0xbac (6a74787f)
6a487372 668b442418      mov     ax,word ptr [esp+18h]
6a487377 897c2430        mov     dword ptr [esp+30h],edi
6a48737b 897c2440        mov     dword ptr [esp+40h],edi
6a48737f 6685c0          test    ax,ax
6a487382 0f849f704300    je      MSHTML!CBase::ContextInvokeEx+0x535 (6a8be427)
6a487388 f6450c04        test    byte ptr [ebp+0Ch],4
6a48738c 0f8595704300    jne     MSHTML!CBase::ContextInvokeEx+0x535 (6a8be427)
6a487392 8b4c241c        mov     ecx,dword ptr [esp+1Ch]
6a487396 0fb7c0          movzx   eax,ax
6a487399 c644240f01      mov     byte ptr [esp+0Fh],1
6a48739e 894c2430        mov     dword ptr [esp+30h],ecx
6a4873a2 8d14851078486a  lea     edx,MSHTML!_FastInvokeTable (6a487810)[eax*4]
6a4873a9 89542440        mov     dword ptr [esp+40h],edx
6a4873ad 8b442430        mov     eax,dword ptr [esp+30h]
6a4873b1 85c0            test    eax,eax
6a4873b3 0f8400010000    je      MSHTML!CBase::ContextInvokeEx+0x3bf (6a4874b9)
6a4873b9 8b5d1c          mov     ebx,dword ptr [ebp+1Ch]
6a4873bc 895c2458        mov     dword ptr [esp+58h],ebx
6a4873c0 897c2460        mov     dword ptr [esp+60h],edi
6a4873c4 85db            test    ebx,ebx
6a4873c6 0f84ef714300    je      MSHTML!CBase::ContextInvokeEx+0x9c7 (6a8be5bb)
6a4873cc 648b352c000000  mov     esi,dword ptr fs:[2Ch]
6a4873d3 a1f46c326b      mov     eax,dword ptr [MSHTML!_tls_index (6b326cf4)]
6a4873d8 8b0486          mov     eax,dword ptr [esi+eax*4]
6a4873db 8b4004          mov     eax,dword ptr [eax+4]
6a4873de 8bb0c4020000    mov     esi,dword ptr [eax+2C4h]
6a4873e4 8998c4020000    mov     dword ptr [eax+2C4h],ebx
6a4873ea 8b442430        mov     eax,dword ptr [esp+30h]
6a4873ee 89742418        mov     dword ptr [esp+18h],esi
6a4873f2 8974245c        mov     dword ptr [esp+5Ch],esi
6a4873f6 8b5c2444        mov     ebx,dword ptr [esp+44h]
6a4873fa 81fb1036706a    cmp     ebx,offset MSHTML!G_IDispatchp (6a703610)
6a487400 0f84d8c12700    je      MSHTML!CBase::ContextInvokeEx+0x655 (6a7035de)
6a487406 81fba07a486a    cmp     ebx,offset MSHTML!GS_BSTR (6a487aa0)
6a48740c 0f8461060000    je      MSHTML!CBase::ContextInvokeEx+0x6a2 (6a487a73)
6a487412 8b542424        mov     edx,dword ptr [esp+24h]
6a487416 8bf4            mov     esi,esp
6a487418 ff742420        push    dword ptr [esp+20h]
6a48741c 52              push    edx
6a48741d ff750c          push    dword ptr [ebp+0Ch]
6a487420 8b54244c        mov     edx,dword ptr [esp+4Ch]
6a487424 ff742434        push    dword ptr [esp+34h]
6a487428 52              push    edx
6a487429 50              push    eax
6a48742a ff751c          push    dword ptr [ebp+1Ch]
6a48742d 51              push    ecx
6a48742e 8bcb            mov     ecx,ebx
6a487430 ff159cef446b    call    dword ptr [MSHTML!__guard_check_icall_fptr (6b44ef9c)]
6a487436 ffd3            call    ebx
6a487438 3bf4            cmp     esi,esp
6a48743a 0f85b56f4300    jne     MSHTML!CBase::ContextInvokeEx+0x371 (6a8be3f5)
6a487440 8b742424        mov     esi,dword ptr [esp+24h]
6a487444 8bd8            mov     ebx,eax
6a487446 85db            test    ebx,ebx
6a487448 0f88ec422c00    js      MSHTML!CBase::ContextInvokeEx+0xb71 (6a74b73a)
6a48744e 8b442434        mov     eax,dword ptr [esp+34h]
6a487452 85c0            test    eax,eax
6a487454 0f85ae575000    jne     MSHTML!`CBackgroundInfo::Property<CBackgroundImage>'::`7'::`dynamic atexit destructor for 'fieldDefaultValue''+0xf6be9 (6a98cc08)
6a48745a 807c240f00      cmp     byte ptr [esp+0Fh],0
6a48745f 7536            jne     MSHTML!CBase::ContextInvokeEx+0x39d (6a487497)
6a487461 8b4c2430        mov     ecx,dword ptr [esp+30h]
6a487465 8b01            mov     eax,dword ptr [ecx]
6a487467 8b7808          mov     edi,dword ptr [eax+8]
6a48746a 81ff00b2256a    cmp     edi,offset MSHTML!COmWindowProxy::Release (6a25b200)
6a487470 0f84db382700    je      MSHTML!CBase::ContextInvokeEx+0x5e4 (6a6fad51)
6a487476 81ffb0a6256a    cmp     edi,offset MSHTML!PlainRelease (6a25a6b0)
6a48747c 0f8432feffff    je      MSHTML!CBase::ContextInvokeEx+0x73f (6a4872b4)
6a487482 8bf4            mov     esi,esp
6a487484 51              push    ecx
6a487485 8bcf            mov     ecx,edi
6a487487 ff159cef446b    call    dword ptr [MSHTML!__guard_check_icall_fptr (6b44ef9c)]
6a48748d ffd7            call    edi
6a48748f 3bf4            cmp     esi,esp
6a487491 0f8518714300    jne     MSHTML!CBase::ContextInvokeEx+0x9bb (6a8be5af)
6a487497 837d1c00        cmp     dword ptr [ebp+1Ch],0
6a48749b 741c            je      MSHTML!CBase::ContextInvokeEx+0x3bf (6a4874b9)
6a48749d 648b0d2c000000  mov     ecx,dword ptr fs:[2Ch]
6a4874a4 a1f46c326b      mov     eax,dword ptr [MSHTML!_tls_index (6b326cf4)]
6a4874a9 8b0481          mov     eax,dword ptr [ecx+eax*4]
6a4874ac 8b4c2418        mov     ecx,dword ptr [esp+18h]
6a4874b0 8b4004          mov     eax,dword ptr [eax+4]
6a4874b3 8988c4020000    mov     dword ptr [eax+2C4h],ecx
6a4874b9 8d442448        lea     eax,[esp+48h]
6a4874bd 50              push    eax
6a4874be ff159849456b    call    dword ptr [MSHTML!_imp__VariantClear (6b454998)]
6a4874c4 8b7c241c        mov     edi,dword ptr [esp+1Ch]
6a4874c8 8b742420        mov     esi,dword ptr [esp+20h]
6a4874cc e990fbffff      jmp     MSHTML!CBase::ContextInvokeEx+0x3d2 (6a487061)

MSHTML!CBase::ContextInvokeEx+0x3d2:
6a487061 81fb03000280    cmp     ebx,80020003h
6a487067 0f84e9ed3000    je      MSHTML!CBase::ContextInvokeEx+0xaa1 (6a795e56)
6a48706d 8b742424        mov     esi,dword ptr [esp+24h]
6a487071 8b442434        mov     eax,dword ptr [esp+34h]
6a487075 85c0            test    eax,eax
6a487077 0f85985d5000    jne     MSHTML!`CBackgroundInfo::Property<CBackgroundImage>'::`7'::`dynamic atexit destructor for 'fieldDefaultValue''+0xf6df6 (6a98ce15)
6a48707d 85db            test    ebx,ebx
6a48707f 0f847c734300    je      MSHTML!CBase::ContextInvokeEx+0x3f2 (6a8be401)
6a487085 0f899d000000    jns     MSHTML!CBase::ContextInvokeEx+0x402 (6a487128)
6a48708b 837d1800        cmp     dword ptr [ebp+18h],0
6a48708f 0f8493000000    je      MSHTML!CBase::ContextInvokeEx+0x402 (6a487128)
6a487095 81fb09000280    cmp     ebx,80020009h
6a48709b 0f8487000000    je      MSHTML!CBase::ContextInvokeEx+0x402 (6a487128)
6a4870a1 ff7518          push    dword ptr [ebp+18h]
6a4870a4 53              push    ebx
6a4870a5 ff742440        push    dword ptr [esp+40h]
6a4870a9 e8193e3100      call    MSHTML!CBase::InitExcepInfo (6a79aec7)
6a4870ae 8bd8            mov     ebx,eax
6a4870b0 eb76            jmp     MSHTML!CBase::ContextInvokeEx+0x402 (6a487128)
6a4870b2 8b5c242c        mov     ebx,dword ptr [esp+2Ch]
6a4870b6 8bcf            mov     ecx,edi
6a4870b8 6aff            push    0FFFFFFFFh
6a4870ba 6a04            push    4
6a4870bc 58              pop     eax
6a4870bd 50              push    eax
6a4870be 53              push    ebx
6a4870bf e8e6cadbff      call    MSHTML!CBase::FindAAIndex (6a243baa)
6a4870c4 83f8ff          cmp     eax,0FFFFFFFFh
6a4870c7 0f8449754300    je      MSHTML!CBase::ContextInvokeEx+0xaeb (6a8be616)
6a4870cd 8364244000      and     dword ptr [esp+40h],0
6a4870d2 8d4c2440        lea     ecx,[esp+40h]
6a4870d6 51              push    ecx
6a4870d7 50              push    eax
6a4870d8 8bcf            mov     ecx,edi
6a4870da e8e3f6ddff      call    MSHTML!CBase::GetPointerAt (6a2667c2)
6a4870df 8b742420        mov     esi,dword ptr [esp+20h]
6a4870e3 85c0            test    eax,eax
6a4870e5 0f854f5c5000    jne     MSHTML!`CBackgroundInfo::Property<CBackgroundImage>'::`7'::`dynamic atexit destructor for 'fieldDefaultValue''+0xf6d1b (6a98cd3a)
6a4870eb 8d4608          lea     eax,[esi+8]
6a4870ee 50              push    eax
6a4870ef 68cc3d246a      push    offset MSHTML!IID_IDispatchEx (6a243dcc)
6a4870f4 ff742448        push    dword ptr [esp+48h]
6a4870f8 e8a30f2c00      call    MSHTML!CFunctionPointer::PrivateQueryInterface (6a7480a0)
6a4870fd 8bd8            mov     ebx,eax
6a4870ff 85db            test    ebx,ebx
6a487101 0f85335c5000    jne     MSHTML!`CBackgroundInfo::Property<CBackgroundImage>'::`7'::`dynamic atexit destructor for 'fieldDefaultValue''+0xf6d1b (6a98cd3a)
6a487107 6a09            push    9
6a487109 59              pop     ecx
6a48710a 66890e          mov     word ptr [esi],cx
6a48710d 8d442448        lea     eax,[esp+48h]
6a487111 50              push    eax
6a487112 ff159849456b    call    dword ptr [MSHTML!_imp__VariantClear (6b454998)]
6a487118 85f6            test    esi,esi
6a48711a 740c            je      MSHTML!CBase::ContextInvokeEx+0x402 (6a487128)
6a48711c 6a09            push    9
6a48711e 58              pop     eax
6a48711f 663906          cmp     word ptr [esi],ax
6a487122 0f845ab12700    je      MSHTML!CBase::ContextInvokeEx+0x419 (6a702282)
6a487128 8b4c2438        mov     ecx,dword ptr [esp+38h]
6a48712c 85c9            test    ecx,ecx
6a48712e 0f8517462c00    jne     MSHTML!CBase::ContextInvokeEx+0xb82 (6a74b74b)
6a487134 8bc3            mov     eax,ebx
6a487136 5f              pop     edi
6a487137 5e              pop     esi
6a487138 5b              pop     ebx
6a487139 8be5            mov     esp,ebp
6a48713b 5d              pop     ebp
6a48713c c21c00          ret     1Ch