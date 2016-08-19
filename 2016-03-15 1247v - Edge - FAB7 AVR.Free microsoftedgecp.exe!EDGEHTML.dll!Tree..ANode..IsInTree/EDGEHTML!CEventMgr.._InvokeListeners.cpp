EDGEHTML!CEventMgr::_InvokeListeners:
65e2c230 8bff            mov     edi,edi
65e2c232 55              push    ebp
65e2c233 8bec            mov     ebp,esp
65e2c235 83e4f8          and     esp,0FFFFFFF8h
65e2c238 81ec84000000    sub     esp,84h
65e2c23e 53              push    ebx
65e2c23f 56              push    esi
65e2c240 8bda            mov     ebx,edx
65e2c242 8a550c          mov     dl,byte ptr [ebp+0Ch]
65e2c245 57              push    edi
65e2c246 8bf9            mov     edi,ecx
65e2c248 897c2428        mov     dword ptr [esp+28h],edi
65e2c24c 84d2            test    dl,dl
65e2c24e 750c            jne     EDGEHTML!CEventMgr::_InvokeListeners+0x2c (65e2c25c)
65e2c250 8b4508          mov     eax,dword ptr [ebp+8]
65e2c253 3b5824          cmp     ebx,dword ptr [eax+24h]
65e2c256 0f847a030000    je      EDGEHTML!CEventMgr::_InvokeListeners+0x3a6 (65e2c5d6)
65e2c25c 8b4730          mov     eax,dword ptr [edi+30h]
65e2c25f 25ffff0000      and     eax,0FFFFh
65e2c264 83f801          cmp     eax,1
65e2c267 0f85c5020000    jne     EDGEHTML!CEventMgr::_InvokeListeners+0x302 (65e2c532)
65e2c26d c644241600      mov     byte ptr [esp+16h],0
65e2c272 8b03            mov     eax,dword ptr [ebx]
65e2c274 817848500f0c66  cmp     dword ptr [eax+48h],offset EDGEHTML!__vtguard (660c0f50)
65e2c27b 0f8562ec3500    jne     EDGEHTML!CEventMgr::_InvokeListeners+0x35ecb3 (6618aee3)
65e2c281 8b8028010000    mov     eax,dword ptr [eax+128h]
65e2c287 89442424        mov     dword ptr [esp+24h],eax
65e2c28b 3dc0cbe265      cmp     eax,offset EDGEHTML!CElement::GetEventTypes (65e2cbc0)
65e2c290 0f853f020000    jne     EDGEHTML!CEventMgr::_InvokeListeners+0x2a5 (65e2c4d5)
65e2c296 6a00            push    0
65e2c298 8bcb            mov     ecx,ebx
65e2c29a e821090000      call    EDGEHTML!CElement::GetEventTypes (65e2cbc0)
65e2c29f 89442410        mov     dword ptr [esp+10h],eax
65e2c2a3 85c0            test    eax,eax
65e2c2a5 7514            jne     EDGEHTML!CEventMgr::_InvokeListeners+0x8b (65e2c2bb)
65e2c2a7 807c241600      cmp     byte ptr [esp+16h],0
65e2c2ac 0f85c5020000    jne     EDGEHTML!CEventMgr::_InvokeListeners+0x347 (65e2c577)
65e2c2b2 5f              pop     edi
65e2c2b3 5e              pop     esi
65e2c2b4 5b              pop     ebx
65e2c2b5 8be5            mov     esp,ebp
65e2c2b7 5d              pop     ebp
65e2c2b8 c20800          ret     8
65e2c2bb 8b03            mov     eax,dword ptr [ebx]
65e2c2bd 33f6            xor     esi,esi
65e2c2bf 89742420        mov     dword ptr [esp+20h],esi
65e2c2c3 817848500f0c66  cmp     dword ptr [eax+48h],offset EDGEHTML!__vtguard (660c0f50)
65e2c2ca 0f8513ec3500    jne     EDGEHTML!CEventMgr::_InvokeListeners+0x35ecb3 (6618aee3)
65e2c2d0 8b80e8000000    mov     eax,dword ptr [eax+0E8h]
65e2c2d6 8b4f38          mov     ecx,dword ptr [edi+38h]
65e2c2d9 89442424        mov     dword ptr [esp+24h],eax
65e2c2dd 3dd0eae265      cmp     eax,offset EDGEHTML!CElement::ShouldSuppressEvent (65e2ead0)
65e2c2e2 0f8527020000    jne     EDGEHTML!CEventMgr::_InvokeListeners+0x2df (65e2c50f)
65e2c2e8 51              push    ecx
65e2c2e9 8bcb            mov     ecx,ebx
65e2c2eb e8e0270000      call    EDGEHTML!CElement::ShouldSuppressEvent (65e2ead0)
65e2c2f0 84c0            test    al,al
65e2c2f2 7514            jne     EDGEHTML!CEventMgr::_InvokeListeners+0xd8 (65e2c308)
65e2c2f4 8b4c2410        mov     ecx,dword ptr [esp+10h]
65e2c2f8 6a00            push    0
65e2c2fa ff7738          push    dword ptr [edi+38h]
65e2c2fd e84e090000      call    EDGEHTML!CEventTypes::GetListeners (65e2cc50)
65e2c302 8bf0            mov     esi,eax
65e2c304 89442420        mov     dword ptr [esp+20h],eax
65e2c308 c644241500      mov     byte ptr [esp+15h],0
65e2c30d 85f6            test    esi,esi
65e2c30f 0f8545020000    jne     EDGEHTML!CEventMgr::_InvokeListeners+0x32a (65e2c55a)
65e2c315 8b4f38          mov     ecx,dword ptr [edi+38h]
65e2c318 8d54241c        lea     edx,[esp+1Ch]
65e2c31c e8cf090000      call    EDGEHTML!CEventMgr::StandardsToWebkitAltDispId (65e2ccf0)
65e2c321 84c0            test    al,al
65e2c323 0f8513030000    jne     EDGEHTML!CEventMgr::_InvokeListeners+0x40c (65e2c63c)
65e2c329 85f6            test    esi,esi
65e2c32b 0f8476ffffff    je      EDGEHTML!CEventMgr::_InvokeListeners+0x77 (65e2c2a7)
65e2c331 8b4730          mov     eax,dword ptr [edi+30h]
65e2c334 25ffff0000      and     eax,0FFFFh
65e2c339 83f801          cmp     eax,1
65e2c33c 0f84b2020000    je      EDGEHTML!CEventMgr::_InvokeListeners+0x3c4 (65e2c5f4)
65e2c342 807e1500        cmp     byte ptr [esi+15h],0
65e2c346 0f84abeb3500    je      EDGEHTML!CEventMgr::_InvokeListeners+0x35ecc7 (6618aef7)
65e2c34c 6a01            push    1
65e2c34e 56              push    esi
65e2c34f 8b7508          mov     esi,dword ptr [ebp+8]
65e2c352 6a04            push    4
65e2c354 8b4e0c          mov     ecx,dword ptr [esi+0Ch]
65e2c357 e879d4f1ff      call    EDGEHTML!CImplAry::Copy (65d497d5)
65e2c35c 8bcf            mov     ecx,edi
65e2c35e 3b5e28          cmp     ebx,dword ptr [esi+28h]
65e2c361 0f842d030000    je      EDGEHTML!CEventMgr::_InvokeListeners+0x464 (65e2c694)
65e2c367 53              push    ebx
65e2c368 e8d22bfeff      call    EDGEHTML!CDOMEvent::SetCurrentTarget (65e0ef3f)
65e2c36d 8d442434        lea     eax,[esp+34h]
65e2c371 c744243400000000 mov     dword ptr [esp+34h],0
65e2c379 50              push    eax
65e2c37a 8bcb            mov     ecx,ebx
65e2c37c e8bbd11700      call    EDGEHTML!CJScript9Holder::GetPrivateSlotValueForWindow (65fa953c)
65e2c381 8b460c          mov     eax,dword ptr [esi+0Ch]
65e2c384 8b4804          mov     ecx,dword ptr [eax+4]
65e2c387 8b5008          mov     edx,dword ptr [eax+8]
65e2c38a 894c242c        mov     dword ptr [esp+2Ch],ecx
65e2c38e 89542424        mov     dword ptr [esp+24h],edx
65e2c392 85c9            test    ecx,ecx
65e2c394 0f8e2e010000    jle     EDGEHTML!CEventMgr::_InvokeListeners+0x298 (65e2c4c8)
65e2c39a 8d9b00000000    lea     ebx,[ebx]
65e2c3a0 0fb74730        movzx   eax,word ptr [edi+30h]
65e2c3a4 8b0a            mov     ecx,dword ptr [edx]
65e2c3a6 50              push    eax
65e2c3a7 894c2414        mov     dword ptr [esp+14h],ecx
65e2c3ab e8b3181b00      call    EDGEHTML!CEventListener::ValidForPhase (65fddc63)
65e2c3b0 84c0            test    al,al
65e2c3b2 0f84f4000000    je      EDGEHTML!CEventMgr::_InvokeListeners+0x27c (65e2c4ac)
65e2c3b8 83794002        cmp     dword ptr [ecx+40h],2
65e2c3bc 0f843b030000    je      EDGEHTML!CEventMgr::_InvokeListeners+0x4cd (65e2c6fd)
65e2c3c2 8d442438        lea     eax,[esp+38h]
65e2c3c6 50              push    eax
65e2c3c7 ff15e400a666    call    dword ptr [EDGEHTML!_imp__VariantInit (66a600e4)]
65e2c3cd 8b442410        mov     eax,dword ptr [esp+10h]
65e2c3d1 83c004          add     eax,4
65e2c3d4 89442418        mov     dword ptr [esp+18h],eax
65e2c3d8 83781400        cmp     dword ptr [eax+14h],0
65e2c3dc 0f85ba020000    jne     EDGEHTML!CEventMgr::_InvokeListeners+0x46c (65e2c69c)
65e2c3e2 8d442430        lea     eax,[esp+30h]
65e2c3e6 c744243000000000 mov     dword ptr [esp+30h],0
65e2c3ee 50              push    eax
65e2c3ef 33d2            xor     edx,edx
65e2c3f1 8bcf            mov     ecx,edi
65e2c3f3 e8185b0100      call    EDGEHTML!CJScript9Holder::CBaseToVar (65e41f10) // Breakpoint
65e2c3f8 ff742430        push    dword ptr [esp+30h]
65e2c3fc 8bcb            mov     ecx,ebx
65e2c3fe e862d11700      call    EDGEHTML!CJScript9Holder::SetPrivateSlotValueForWindow (65fa9565)
65e2c403 33c9            xor     ecx,ecx
65e2c405 894c241c        mov     dword ptr [esp+1Ch],ecx
65e2c409 e8f4620000      call    EDGEHTML!CDebugCallbackNotificationHandlers::AreAnyListenersFastCheck (65e32702)
65e2c40e 84c0            test    al,al
65e2c410 0f85efea3500    jne     EDGEHTML!CEventMgr::_InvokeListeners+0x35ecd5 (6618af05)
65e2c416 807c241500      cmp     byte ptr [esp+15h],0
65e2c41b 0f8519eb3500    jne     EDGEHTML!CEventMgr::_InvokeListeners+0x35ed0a (6618af3a)
65e2c421 8b442410        mov     eax,dword ptr [esp+10h]
65e2c425 83784002        cmp     dword ptr [eax+40h],2
65e2c429 0f84dc020000    je      EDGEHTML!CEventMgr::_InvokeListeners+0x4db (65e2c70b)
65e2c42f 8d4c2438        lea     ecx,[esp+38h]
65e2c433 51              push    ecx
65e2c434 56              push    esi
65e2c435 50              push    eax
65e2c436 57              push    edi
65e2c437 8d4804          lea     ecx,[eax+4]
65e2c43a e864291700      call    EDGEHTML!CListenerDispatch::Invoke (65f9eda3) // Use-after-free
65e2c43f 8bc8            mov     ecx,eax
65e2c441 894c2420        mov     dword ptr [esp+20h],ecx
65e2c445 e875961000      call    EDGEHTML!CJScript9Holder::IsRecordedException (65f35abf)
65e2c44a 84c0            test    al,al
65e2c44c 0f85f4ea3500    jne     EDGEHTML!CEventMgr::_InvokeListeners+0x35ed16 (6618af46)
65e2c452 807c241500      cmp     byte ptr [esp+15h],0
65e2c457 0f852eeb3500    jne     EDGEHTML!CEventMgr::_InvokeListeners+0x35ed5b (6618af8b)
65e2c45d 85c9            test    ecx,ecx
65e2c45f 751c            jne     EDGEHTML!CEventMgr::_InvokeListeners+0x24d (65e2c47d)
65e2c461 817f402834a465  cmp     dword ptr [edi+40h],offset EDGEHTML!s_propdescCIE9EventListbeforeunload (65a43428)
65e2c468 668b4c2438      mov     cx,word ptr [esp+38h]
65e2c46d 0f844c020000    je      EDGEHTML!CEventMgr::_InvokeListeners+0x48f (65e2c6bf)
65e2c473 6683f90b        cmp     cx,0Bh
65e2c477 0f8450020000    je      EDGEHTML!CEventMgr::_InvokeListeners+0x49d (65e2c6cd)
65e2c47d 8b442410        mov     eax,dword ptr [esp+10h]
65e2c481 8b4c241c        mov     ecx,dword ptr [esp+1Ch]
65e2c485 85c9            test    ecx,ecx
65e2c487 0f8557eb3500    jne     EDGEHTML!CEventMgr::_InvokeListeners+0x35edb4 (6618afe4)
65e2c48d ff742434        push    dword ptr [esp+34h]
65e2c491 8bcb            mov     ecx,ebx
65e2c493 e8cdd01700      call    EDGEHTML!CJScript9Holder::SetPrivateSlotValueForWindow (65fa9565)
65e2c498 8d442438        lea     eax,[esp+38h]
65e2c49c 50              push    eax
65e2c49d ff15ec00a666    call    dword ptr [EDGEHTML!_imp__VariantClear (66a600ec)]
65e2c4a3 f7473000001000  test    dword ptr [edi+30h],100000h
65e2c4aa 751c            jne     EDGEHTML!CEventMgr::_InvokeListeners+0x298 (65e2c4c8)
65e2c4ac 8b44242c        mov     eax,dword ptr [esp+2Ch]
65e2c4b0 8b542424        mov     edx,dword ptr [esp+24h]
65e2c4b4 48              dec     eax
65e2c4b5 83c204          add     edx,4
65e2c4b8 8944242c        mov     dword ptr [esp+2Ch],eax
65e2c4bc 89542424        mov     dword ptr [esp+24h],edx
65e2c4c0 85c0            test    eax,eax
65e2c4c2 0f8fd8feffff    jg      EDGEHTML!CEventMgr::_InvokeListeners+0x170 (65e2c3a0)
65e2c4c8 8b4e0c          mov     ecx,dword ptr [esi+0Ch]
65e2c4cb e80015f6ff      call    EDGEHTML!CImplPtrAry::ReleaseAll (65d8d9d0)
65e2c4d0 e9d2fdffff      jmp     EDGEHTML!CEventMgr::_InvokeListeners+0x77 (65e2c2a7)
65e2c4d5 3de07fed65      cmp     eax,offset EDGEHTML!COmWindowProxy::GetEventTypes (65ed7fe0)
65e2c4da 0f8489000000    je      EDGEHTML!CEventMgr::_InvokeListeners+0x339 (65e2c569)
65e2c4e0 3d9084ed65      cmp     eax,offset EDGEHTML!CDocument::GetEventTypes (65ed8490)
65e2c4e5 0f84dd000000    je      EDGEHTML!CEventMgr::_InvokeListeners+0x398 (65e2c5c8)
65e2c4eb 3d2004fd65      cmp     eax,offset EDGEHTML!CWindow::GetEventTypes (65fd0420)
65e2c4f0 0f84f0000000    je      EDGEHTML!CEventMgr::_InvokeListeners+0x3b6 (65e2c5e6)
65e2c4f6 3d3080ed65      cmp     eax,offset EDGEHTML!CXMLHttpRequest::GetEventTypes (65ed8030)
65e2c4fb 0f850b010000    jne     EDGEHTML!CEventMgr::_InvokeListeners+0x3dc (65e2c60c)
65e2c501 6a00            push    0
65e2c503 8bcb            mov     ecx,ebx
65e2c505 e826bb0a00      call    EDGEHTML!CXMLHttpRequest::GetEventTypes (65ed8030)
65e2c50a e990fdffff      jmp     EDGEHTML!CEventMgr::_InvokeListeners+0x6f (65e2c29f)
65e2c50f 8bf4            mov     esi,esp
65e2c511 51              push    ecx
65e2c512 8bc8            mov     ecx,eax
65e2c514 ff152cbba566    call    dword ptr [EDGEHTML!__guard_check_icall_fptr (66a5bb2c)]
65e2c51a 8bcb            mov     ecx,ebx
65e2c51c ff542428        call    dword ptr [esp+28h]
65e2c520 3bf4            cmp     esi,esp
65e2c522 7407            je      EDGEHTML!CEventMgr::_InvokeListeners+0x2fb (65e2c52b)
65e2c524 b904000000      mov     ecx,4
65e2c529 cd29            int     29h
65e2c52b 33f6            xor     esi,esi
65e2c52d e9befdffff      jmp     EDGEHTML!CEventMgr::_InvokeListeners+0xc0 (65e2c2f0)
65e2c532 8b4d08          mov     ecx,dword ptr [ebp+8]
65e2c535 83791000        cmp     dword ptr [ecx+10h],0
65e2c539 0f842efdffff    je      EDGEHTML!CEventMgr::_InvokeListeners+0x3d (65e2c26d)
65e2c53f 84d2            test    dl,dl
65e2c541 0f85e7000000    jne     EDGEHTML!CEventMgr::_InvokeListeners+0x3fe (65e2c62e)
65e2c547 803900          cmp     byte ptr [ecx],0
65e2c54a 0f851dfdffff    jne     EDGEHTML!CEventMgr::_InvokeListeners+0x3d (65e2c26d)
65e2c550 c644241601      mov     byte ptr [esp+16h],1
65e2c555 e918fdffff      jmp     EDGEHTML!CEventMgr::_InvokeListeners+0x42 (65e2c272)
65e2c55a 837e0400        cmp     dword ptr [esi+4],0
65e2c55e 0f85c5fdffff    jne     EDGEHTML!CEventMgr::_InvokeListeners+0xf9 (65e2c329)
65e2c564 e9acfdffff      jmp     EDGEHTML!CEventMgr::_InvokeListeners+0xe5 (65e2c315)
65e2c569 6a00            push    0
65e2c56b 8bcb            mov     ecx,ebx
65e2c56d e86eba0a00      call    EDGEHTML!COmWindowProxy::GetEventTypes (65ed7fe0)
65e2c572 e928fdffff      jmp     EDGEHTML!CEventMgr::_InvokeListeners+0x6f (65e2c29f)
65e2c577 8b03            mov     eax,dword ptr [ebx]
65e2c579 817848500f0c66  cmp     dword ptr [eax+48h],offset EDGEHTML!__vtguard (660c0f50)
65e2c580 0f855de93500    jne     EDGEHTML!CEventMgr::_InvokeListeners+0x35ecb3 (6618aee3)
65e2c586 8bb8f0000000    mov     edi,dword ptr [eax+0F0h]
65e2c58c 81ff70bcdc65    cmp     edi,offset EDGEHTML!CElement::HasEventSink (65dcbc70)
65e2c592 746f            je      EDGEHTML!CEventMgr::_InvokeListeners+0x3d3 (65e2c603)
65e2c594 8bcf            mov     ecx,edi
65e2c596 8bf4            mov     esi,esp
65e2c598 ff152cbba566    call    dword ptr [EDGEHTML!__guard_check_icall_fptr (66a5bb2c)]
65e2c59e 8bcb            mov     ecx,ebx
65e2c5a0 ffd7            call    edi
65e2c5a2 3bf4            cmp     esi,esp
65e2c5a4 7407            je      EDGEHTML!CEventMgr::_InvokeListeners+0x37d (65e2c5ad)
65e2c5a6 b904000000      mov     ecx,4
65e2c5ab cd29            int     29h
65e2c5ad 84c0            test    al,al
65e2c5af 0f84fdfcffff    je      EDGEHTML!CEventMgr::_InvokeListeners+0x82 (65e2c2b2)
65e2c5b5 ff7508          push    dword ptr [ebp+8]
65e2c5b8 8b4c242c        mov     ecx,dword ptr [esp+2Ch]
65e2c5bc 8bd3            mov     edx,ebx
65e2c5be e881121100      call    EDGEHTML!CEventMgr::_InvokeSinks (65f3d844)
65e2c5c3 e9eafcffff      jmp     EDGEHTML!CEventMgr::_InvokeListeners+0x82 (65e2c2b2)
65e2c5c8 6a00            push    0
65e2c5ca 8bcb            mov     ecx,ebx
65e2c5cc e8bfbe0a00      call    EDGEHTML!CDocument::GetEventTypes (65ed8490)
65e2c5d1 e9c9fcffff      jmp     EDGEHTML!CEventMgr::_InvokeListeners+0x6f (65e2c29f)
65e2c5d6 8bd0            mov     edx,eax
65e2c5d8 e8683c1900      call    EDGEHTML!CEventMgr::_InvokeListenersOnWindow (65fc0245)
65e2c5dd 5f              pop     edi
65e2c5de 5e              pop     esi
65e2c5df 5b              pop     ebx
65e2c5e0 8be5            mov     esp,ebp
65e2c5e2 5d              pop     ebp
65e2c5e3 c20800          ret     8
65e2c5e6 6a00            push    0
65e2c5e8 8bcb            mov     ecx,ebx
65e2c5ea e8313e1a00      call    EDGEHTML!CWindow::GetEventTypes (65fd0420)
65e2c5ef e9abfcffff      jmp     EDGEHTML!CEventMgr::_InvokeListeners+0x6f (65e2c29f)
65e2c5f4 807e1400        cmp     byte ptr [esi+14h],0
65e2c5f8 0f84a9fcffff    je      EDGEHTML!CEventMgr::_InvokeListeners+0x77 (65e2c2a7)
65e2c5fe e949fdffff      jmp     EDGEHTML!CEventMgr::_InvokeListeners+0x11c (65e2c34c)
65e2c603 8bcb            mov     ecx,ebx
65e2c605 e866f6f9ff      call    EDGEHTML!CElement::HasEventSink (65dcbc70)
65e2c60a eba1            jmp     EDGEHTML!CEventMgr::_InvokeListeners+0x37d (65e2c5ad)
65e2c60c 8bf4            mov     esi,esp
65e2c60e 8bc8            mov     ecx,eax
65e2c610 6a00            push    0
65e2c612 ff152cbba566    call    dword ptr [EDGEHTML!__guard_check_icall_fptr (66a5bb2c)]
65e2c618 8bcb            mov     ecx,ebx
65e2c61a ff542428        call    dword ptr [esp+28h]
65e2c61e 3bf4            cmp     esi,esp
65e2c620 7407            je      EDGEHTML!CEventMgr::_InvokeListeners+0x3f9 (65e2c629)
65e2c622 b904000000      mov     ecx,4
65e2c627 cd29            int     29h
65e2c629 e971fcffff      jmp     EDGEHTML!CEventMgr::_InvokeListeners+0x6f (65e2c29f)
65e2c62e 83f802          cmp     eax,2
65e2c631 0f8410ffffff    je      EDGEHTML!CEventMgr::_InvokeListeners+0x317 (65e2c547)
65e2c637 e931fcffff      jmp     EDGEHTML!CEventMgr::_InvokeListeners+0x3d (65e2c26d)
65e2c63c 8b33            mov     esi,dword ptr [ebx]
65e2c63e 817e48500f0c66  cmp     dword ptr [esi+48h],offset EDGEHTML!__vtguard (660c0f50)
65e2c645 0f8598e83500    jne     EDGEHTML!CEventMgr::_InvokeListeners+0x35ecb3 (6618aee3)
65e2c64b 8bb6e8000000    mov     esi,dword ptr [esi+0E8h]
65e2c651 8bfc            mov     edi,esp
65e2c653 ff74241c        push    dword ptr [esp+1Ch]
65e2c657 8bce            mov     ecx,esi
65e2c659 ff152cbba566    call    dword ptr [EDGEHTML!__guard_check_icall_fptr (66a5bb2c)]
65e2c65f 8bcb            mov     ecx,ebx
65e2c661 ffd6            call    esi
65e2c663 3bfc            cmp     edi,esp
65e2c665 7407            je      EDGEHTML!CEventMgr::_InvokeListeners+0x43e (65e2c66e)
65e2c667 b904000000      mov     ecx,4
65e2c66c cd29            int     29h
65e2c66e 84c0            test    al,al
65e2c670 0f8574e83500    jne     EDGEHTML!CEventMgr::_InvokeListeners+0x35ecba (6618aeea)
65e2c676 8b4c2410        mov     ecx,dword ptr [esp+10h]
65e2c67a 6a00            push    0
65e2c67c ff742420        push    dword ptr [esp+20h]
65e2c680 e8cb050000      call    EDGEHTML!CEventTypes::GetListeners (65e2cc50)
65e2c685 8bf0            mov     esi,eax
65e2c687 85f6            test    esi,esi
65e2c689 0f8418fcffff    je      EDGEHTML!CEventMgr::_InvokeListeners+0x77 (65e2c2a7)
65e2c68f e948e83500      jmp     EDGEHTML!CEventMgr::_InvokeListeners+0x35ecac (6618aedc)
65e2c694 ff762c          push    dword ptr [esi+2Ch]
65e2c697 e9ccfcffff      jmp     EDGEHTML!CEventMgr::_InvokeListeners+0x138 (65e2c368)
65e2c69c 8d4c2417        lea     ecx,[esp+17h]
65e2c6a0 51              push    ecx
65e2c6a1 8bc8            mov     ecx,eax
65e2c6a3 e814252300      call    EDGEHTML!CListenerDispatch::ConstructCode (6605ebbc)
65e2c6a8 85c0            test    eax,eax
65e2c6aa 0f85e8fdffff    jne     EDGEHTML!CEventMgr::_InvokeListeners+0x268 (65e2c498)
65e2c6b0 38442417        cmp     byte ptr [esp+17h],al
65e2c6b4 0f8528fdffff    jne     EDGEHTML!CEventMgr::_InvokeListeners+0x1b2 (65e2c3e2)
65e2c6ba e9d9fdffff      jmp     EDGEHTML!CEventMgr::_InvokeListeners+0x268 (65e2c498)
65e2c6bf 6685c9          test    cx,cx
65e2c6c2 0f84abfdffff    je      EDGEHTML!CEventMgr::_InvokeListeners+0x243 (65e2c473)
65e2c6c8 e9cae83500      jmp     EDGEHTML!CEventMgr::_InvokeListeners+0x35ed67 (6618af97)
65e2c6cd 837e3000        cmp     dword ptr [esi+30h],0
65e2c6d1 8b442410        mov     eax,dword ptr [esp+10h]
65e2c6d5 0f85f8e83500    jne     EDGEHTML!CEventMgr::_InvokeListeners+0x35eda3 (6618afd3)
65e2c6db 83784000        cmp     dword ptr [eax+40h],0
65e2c6df 0f849cfdffff    je      EDGEHTML!CEventMgr::_InvokeListeners+0x251 (65e2c481)
65e2c6e5 66837c244000    cmp     word ptr [esp+40h],0
65e2c6eb 0f8590fdffff    jne     EDGEHTML!CEventMgr::_InvokeListeners+0x251 (65e2c481)
65e2c6f1 814f3000002000  or      dword ptr [edi+30h],200000h
65e2c6f8 e984fdffff      jmp     EDGEHTML!CEventMgr::_InvokeListeners+0x251 (65e2c481)
65e2c6fd 803e00          cmp     byte ptr [esi],0
65e2c700 0f84bcfcffff    je      EDGEHTML!CEventMgr::_InvokeListeners+0x192 (65e2c3c2)
65e2c706 e9a1fdffff      jmp     EDGEHTML!CEventMgr::_InvokeListeners+0x27c (65e2c4ac)
65e2c70b 8b4c2418        mov     ecx,dword ptr [esp+18h]
65e2c70f 8d44244c        lea     eax,[esp+4Ch]
65e2c713 50              push    eax
65e2c714 e804980a00      call    EDGEHTML!CListenerDispatch::GetDisp (65ed5f1d)
65e2c719 8bc8            mov     ecx,eax
65e2c71b 85c9            test    ecx,ecx
65e2c71d 0f852ffdffff    jne     EDGEHTML!CEventMgr::_InvokeListeners+0x222 (65e2c452)
65e2c723 b809000000      mov     eax,9
65e2c728 894c2450        mov     dword ptr [esp+50h],ecx
65e2c72c 6689442460      mov     word ptr [esp+60h],ax
65e2c731 8d7c2470        lea     edi,[esp+70h]
65e2c735 894c2454        mov     dword ptr [esp+54h],ecx
65e2c739 33c0            xor     eax,eax
65e2c73b 894c2458        mov     dword ptr [esp+58h],ecx
65e2c73f 894c245c        mov     dword ptr [esp+5Ch],ecx
65e2c743 b908000000      mov     ecx,8
65e2c748 f3ab            rep stos dword ptr es:[edi]
65e2c74a 8b4630          mov     eax,dword ptr [esi+30h]
65e2c74d 85c0            test    eax,eax
65e2c74f 0f85a4000000    jne     EDGEHTML!CEventMgr::_InvokeListeners+0x5c9 (65e2c7f9)
65e2c755 8b4e10          mov     ecx,dword ptr [esi+10h]
65e2c758 85c9            test    ecx,ecx
65e2c75a 743a            je      EDGEHTML!CEventMgr::_InvokeListeners+0x566 (65e2c796)
65e2c75c 837e1400        cmp     dword ptr [esi+14h],0
65e2c760 8d4614          lea     eax,[esi+14h]
65e2c763 89442418        mov     dword ptr [esp+18h],eax
65e2c767 752d            jne     EDGEHTML!CEventMgr::_InvokeListeners+0x566 (65e2c796)
65e2c769 8b31            mov     esi,dword ptr [ecx]
65e2c76b 8bfc            mov     edi,esp
65e2c76d 50              push    eax
65e2c76e 68c030a365      push    offset EDGEHTML!_GUID_a6ef9860_c720_11d0_9337_00a0c90dcaa9 (65a330c0)
65e2c773 51              push    ecx
65e2c774 8b36            mov     esi,dword ptr [esi]
65e2c776 8bce            mov     ecx,esi
65e2c778 ff152cbba566    call    dword ptr [EDGEHTML!__guard_check_icall_fptr (66a5bb2c)]
65e2c77e ffd6            call    esi
65e2c780 3bfc            cmp     edi,esp
65e2c782 7407            je      EDGEHTML!CEventMgr::_InvokeListeners+0x55b (65e2c78b)
65e2c784 b904000000      mov     ecx,4
65e2c789 cd29            int     29h
65e2c78b 8b7508          mov     esi,dword ptr [ebp+8]
65e2c78e 85c0            test    eax,eax
65e2c790 0f85e6e73500    jne     EDGEHTML!CEventMgr::_InvokeListeners+0x35ed4c (6618af7c)
65e2c796 8b4614          mov     eax,dword ptr [esi+14h]
65e2c799 8d4c2460        lea     ecx,[esp+60h]
65e2c79d 89442468        mov     dword ptr [esp+68h],eax
65e2c7a1 8d442450        lea     eax,[esp+50h]
65e2c7a5 8b74244c        mov     esi,dword ptr [esp+4Ch]
65e2c7a9 51              push    ecx
65e2c7aa 51              push    ecx
65e2c7ab 8d4c2478        lea     ecx,[esp+78h]
65e2c7af 51              push    ecx
65e2c7b0 8d4c2444        lea     ecx,[esp+44h]
65e2c7b4 51              push    ecx
65e2c7b5 50              push    eax
65e2c7b6 83ec0c          sub     esp,0Ch
65e2c7b9 56              push    esi
65e2c7ba e87bf52200      call    EDGEHTML!CBase::InvokeDispatchExtraParam (6605bd3a)
65e2c7bf 89442420        mov     dword ptr [esp+20h],eax
65e2c7c3 8bfc            mov     edi,esp
65e2c7c5 8b06            mov     eax,dword ptr [esi]
65e2c7c7 56              push    esi
65e2c7c8 8b7008          mov     esi,dword ptr [eax+8]
65e2c7cb 8bce            mov     ecx,esi
65e2c7cd ff152cbba566    call    dword ptr [EDGEHTML!__guard_check_icall_fptr (66a5bb2c)]
65e2c7d3 ffd6            call    esi
65e2c7d5 3bfc            cmp     edi,esp
65e2c7d7 7407            je      EDGEHTML!CEventMgr::_InvokeListeners+0x5b0 (65e2c7e0)
65e2c7d9 b904000000      mov     ecx,4
65e2c7de cd29            int     29h
65e2c7e0 8d4c2470        lea     ecx,[esp+70h]
65e2c7e4 e8d16f1100      call    EDGEHTML!FreeEXCEPINFO (65f437ba)
65e2c7e9 8b7c2428        mov     edi,dword ptr [esp+28h]
65e2c7ed 8b7508          mov     esi,dword ptr [ebp+8]
65e2c7f0 8b4c2420        mov     ecx,dword ptr [esp+20h]
65e2c7f4 e959fcffff      jmp     EDGEHTML!CEventMgr::_InvokeListeners+0x222 (65e2c452)
65e2c7f9 33c9            xor     ecx,ecx
65e2c7fb eba8            jmp     EDGEHTML!CEventMgr::_InvokeListeners+0x575 (65e2c7a5)
