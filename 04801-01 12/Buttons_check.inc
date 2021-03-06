      ;******* - �������� ������� ������ � ������� ������� D5 � D6**************************
     ;******* �������: �������� ������� ����������:                    *********************
    ;******* POW_ON; POW_OFF; TEST; RES;  --			����� OE_BTN1
   ;******S_12MS,S_21MS,S_300MS,S_1100MS,S_OK,S_SEL --  ����� OE_BTN1 *******************
  ;****** S2_x..S9_x:=1 - ��������������� ������� �� ������. ****************************
 ;****** ����������� ���������� �������������� ������� ���������� ������. **************
;**************************************************************************************
;+BONUS : ��������� TEST_BUTTONS - ��� �������� ����������
;**************************************************************************************

TTI_S:
;** 26-01-2011 ***********************************************************************************

MOV P2, #0FFH

;************** ����� OE_BTN1 ****************************************************************
    SETB	OE_BTN2
	CLR	OE_BTN1
			   
			    mov     B,#1   ; B:= ���������� ������,
                               ;     ������������ ����� ����� �������� �������.
                ;-------------; ********************************************************
                             ; ********************************************************
                setb    POW_ON ; ����� � �������� ��������� �������� ������� ����������.
                setb    POW_OFF
                setb    TEST
                setb    RES
                setb    S_12MS ; ����� � �������� ��������� �������� ������� ����������.
                setb    S_21MS
                setb    S_300MS
                setb    S_1100MS
                setb    S_OK
                setb    S_SEL

                ;-------------------------------------------------------------
TTI_S_1:
                
						
				jb      PORT_POW_ON,TTI_S_2
				
                ;-------------------------------------
       ;- �������������� �������� ������� ������ � ���� PORT_POW_ON. ---
                mov     R7,#20
                lcall   delay_n_x_1_ms ; �������� 20 ��.
                jnb     PORT_POW_ON,TTI_S1_SET
                ;--
                SETB	OE_BTN1
				SETB	OE_BTN2
				ret
TTI_S1_SET:
                clr     POW_ON
                lcall   KONTROL_NO_PRESSING; �������� ���������� ���� ������ ������.
                ;--
                SETB	OE_BTN1
				SETB	OE_BTN2
				ret


TTI_S_2:
                	
				jb      PORT_POW_OFF,TTI_S_3
                		
				;----------------------------------
       ;- �������������� �������� ������� ������ � ���� PORT_POW_OFF. ---
                mov     R7,#20
                lcall   delay_n_x_1_ms ; �������� 20 ��.
                jnb     PORT_POW_OFF,TTI_S2_SET
                ;--
                SETB	OE_BTN1
				SETB	OE_BTN2
				ret
TTI_S2_SET:
                clr     POW_OFF
				lcall   KONTROL_NO_PRESSING; �������� ���������� ���� ������ ������.
                ;--
                SETB	OE_BTN1
				SETB	OE_BTN2
				ret


TTI_S_3:
                	
				jb      PORT_TEST,TTI_S_4
                	
				;----------------------------------
       ;- �������������� �������� ������� ������ � ���� PORT_S4_VKL. ---
                mov     R7,#20
                lcall   delay_n_x_1_ms ; �������� 20 ��.
                jnb     PORT_TEST,TTI_S3_SET
                ;--
                SETB	OE_BTN1
				SETB	OE_BTN2
				ret
TTI_S3_SET:
                clr     TEST
                lcall   KONTROL_NO_PRESSING; �������� ���������� ���� ������ ������.
                ;--
                SETB	OE_BTN1
				SETB	OE_BTN2
				ret


TTI_S_4:
                
				jb      PORT_RES,TTI_S_5
                	
				;----------------------------------
       ;- �������������� �������� ������� ������ � ���� PORT_RES. ---
                mov     R7,#20
                lcall   delay_n_x_1_ms ; �������� 20 ��.
                jnb     PORT_RES,TTI_S4_SET
                ;--
                SETB	OE_BTN1
				SETB	OE_BTN2
				ret
TTI_S4_SET:
                clr     RES
                lcall   KONTROL_NO_PRESSING; �������� ���������� ���� ������ ������.
                ;--
                SETB	OE_BTN1
				SETB	OE_BTN2
				ret
;************** ����� OE_BTN1 ****************************************************************
 
;************** ����� OE_BTN2 ****************************************************************



TTI_S_5:
SETB	OE_BTN1
CLR		OE_BTN2                
				jb      PORT_12MS,TTI_S_6
                	
				;----------------------------------
       ;- �������������� �������� ������� ������ � ���� PORT_12MS. ---
                mov     R7,#20
                lcall   delay_n_x_1_ms ; �������� 20 ��.
                jnb     PORT_12MS,TTI_S5_SET
                ;--
                SETB	OE_BTN1
				SETB	OE_BTN2
				ret
TTI_S5_SET:
                clr     S_12MS
                lcall   KONTROL_NO_PRESSING2; �������� ���������� ���� ������ ������.
                ;--
                SETB	OE_BTN1
				SETB	OE_BTN2
				ret


TTI_S_6:
                
				jb      PORT_21MS,TTI_S_7
                	
				;----------------------------------
       ;- �������������� �������� ������� ������ � ���� PORT_12MS. ---
                mov     R7,#20
                lcall   delay_n_x_1_ms ; �������� 20 ��.
                jnb     PORT_21MS,TTI_S6_SET
                ;--
                SETB	OE_BTN1
				SETB	OE_BTN2
				ret
TTI_S6_SET:
                clr     S_21MS
                lcall   KONTROL_NO_PRESSING2; �������� ���������� ���� ������ ������.
                ;--
                SETB	OE_BTN1
				SETB	OE_BTN2
				ret






TTI_S_7:
                
				jb      PORT_300MS,TTI_S_8
                	
				;----------------------------------
       ;- �������������� �������� ������� ������ � ���� PORT_300MS. ---
                mov     R7,#20
                lcall   delay_n_x_1_ms ; �������� 20 ��.
                jnb     PORT_300MS,TTI_S7_SET
                ;--
                SETB	OE_BTN1
                SETB	OE_BTN2
				ret
TTI_S7_SET:
                clr     S_300MS
                lcall   KONTROL_NO_PRESSING2; �������� ���������� ���� ������ ������.
                ;--
                SETB	OE_BTN1
				SETB	OE_BTN2
				ret



TTI_S_8:
                
				jb      PORT_1100MS,TTI_S_9
                	
				;----------------------------------
       ;- �������������� �������� ������� ������ � ���� PORT_1100MS. ---
                mov     R7,#20
                lcall   delay_n_x_1_ms ; �������� 20 ��.
                jnb     PORT_1100MS,TTI_S8_SET
                ;--
                SETB	OE_BTN1
				SETB	OE_BTN2
				ret
TTI_S8_SET:
                clr     S_1100MS
                lcall   KONTROL_NO_PRESSING2; �������� ���������� ���� ������ ������.
                ;--
                SETB	OE_BTN1
				SETB	OE_BTN2
				ret




TTI_S_9:
                
				jb      PORT_OK,TTI_S_10
                	
				;----------------------------------
       ;- �������������� �������� ������� ������ � ���� PORT_OK. ---
                mov     R7,#20
                lcall   delay_n_x_1_ms ; �������� 20 ��.
                jnb     PORT_OK,TTI_S9_SET
                ;--
                SETB	OE_BTN1
				SETB	OE_BTN2
				ret
TTI_S9_SET:
                clr     S_OK
                lcall   KONTROL_NO_PRESSING2; �������� ���������� ���� ������ ������.
                ;--
                SETB	OE_BTN1
				SETB	OE_BTN2
				ret


TTI_S_10:
                
				jb      PORT_SEL,TTI_S_CUKL
                	
				;----------------------------------
       ;- �������������� �������� ������� ������ � ���� PORT_SEL. ---
                mov     R7,#20
                lcall   delay_n_x_1_ms ; �������� 20 ��.
                jnb     PORT_SEL,TTI_S10_SET
                ;--
                SETB	OE_BTN1
                SETB	OE_BTN2
				ret
TTI_S10_SET:
                clr     S_SEL
                lcall   KONTROL_NO_PRESSING2; �������� ���������� ���� ������ ������.
                ;--
                SETB	OE_BTN1
				SETB	OE_BTN2
				ret
;************** ����� OE_BTN2 ****************************************************************


TTI_S_CUKL:
                djnz    B,TTI_S_1_000
                ;------------------------------------------------------------------------------
                SETB	OE_BTN1
				SETB	OE_BTN2
				ret
                ;****************************************************************
TTI_S_1_000:
                ljmp    TTI_S_1
                ;****************************************************************


  ;*************************************************************************************
 ;*** �������� ���������� ������ ������ OE_BTN1(������ � ��. TTI_S)                     *
;*************************************************************************************
KONTROL_NO_PRESSING:
                ;-- �������� ������: ��� �� ��������? -------------------------------
NO_TTI_S_1:
                	
				jb      PORT_POW_ON,NO_TTI_S_2
                
				;----------------------------------
                ;-------------
                jnb     PORT_POW_ON,$
                ;-------------
                mov     R7,#5
                lcall   delay_n_x_1_ms ; �������� 5 ��.
                ljmp    NO_TTI_S_1
                ;----------------------------------

NO_TTI_S_2:
                jb      PORT_POW_OFF,NO_TTI_S_3
                ;----------------------------------
                ;-------------
                jnb     PORT_POW_OFF,$
                ;-------------
                mov     R7,#5
                lcall   delay_n_x_1_ms ; �������� 5 ��.
                ljmp    NO_TTI_S_2
                ;----------------------------------

NO_TTI_S_3:
                jb      PORT_TEST,NO_TTI_S_4
                ;----------------------------------
                ;-------------
                jnb     PORT_TEST,$
                ;-------------
                mov     R7,#5
                lcall   delay_n_x_1_ms ; �������� 5 ��.
                ljmp    NO_TTI_S_3
                ;----------------------------------

NO_TTI_S_4:
                jb      PORT_RES,EX_KONTROL_NO_PRESSING
                ;----------------------------------
                ;-------------
                jnb     PORT_RES,$
                ;-------------
                mov     R7,#5
                lcall   delay_n_x_1_ms ; �������� 5 ��.
                ljmp    NO_TTI_S_4
                ;----------------------------------


EX_KONTROL_NO_PRESSING:
                ret



  ;*************************************************************************************
 ;*** �������� ���������� ������ ������ OE_BTN2(������ � ��. TTI_S)                     *
;*************************************************************************************

KONTROL_NO_PRESSING2:
                ;-- �������� ������: ��� �� ��������? -------------------------------
NO_TTI_S_5:
                	
				jb      PORT_12MS,NO_TTI_S_6
                
				;----------------------------------
                ;-------------
                jnb     PORT_12MS,$
                ;-------------
                mov     R7,#5
                lcall   delay_n_x_1_ms ; �������� 5 ��.
                ljmp    NO_TTI_S_5
                ;----------------------------------

NO_TTI_S_6:
                jb      PORT_21MS,NO_TTI_S_7
                ;----------------------------------
                ;-------------
                jnb     PORT_21MS,$
                ;-------------
                mov     R7,#5
                lcall   delay_n_x_1_ms ; �������� 5 ��.
                ljmp    NO_TTI_S_6
                ;----------------------------------

NO_TTI_S_7:
                jb      PORT_300MS,NO_TTI_S_8
                ;----------------------------------
                ;-------------
                jnb     PORT_300MS,$
                ;-------------
                mov     R7,#5
                lcall   delay_n_x_1_ms ; �������� 5 ��.
                ljmp    NO_TTI_S_7
                ;----------------------------------



NO_TTI_S_8:
                jb      PORT_1100MS,NO_TTI_S_9
                ;----------------------------------
                ;-------------
                jnb     PORT_1100MS,$
                ;-------------
                mov     R7,#5
                lcall   delay_n_x_1_ms ; �������� 5 ��.
                ljmp    NO_TTI_S_8
                ;----------------------------------



NO_TTI_S_9:
                jb      PORT_OK,NO_TTI_S_10
                ;----------------------------------
                ;-------------
                jnb     PORT_OK,$
                ;-------------
                mov     R7,#5
                lcall   delay_n_x_1_ms ; �������� 5 ��.
                ljmp    NO_TTI_S_9
                ;----------------------------------



NO_TTI_S_10:
                jb      PORT_SEL,EX_KONTROL_NO_PRESSING2
                ;----------------------------------
                ;-------------
                jnb     PORT_SEL,$
                ;-------------
                mov     R7,#5
                lcall   delay_n_x_1_ms ; �������� 5 ��.
                ljmp    NO_TTI_S_10
                ;----------------------------------



EX_KONTROL_NO_PRESSING2:
                ret
                ;****************************************************************
;********************************************************************************










TEST_BUTTONS:
;************************************************************************************
  ;!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ;**************** �������� ������ ������ ���� *****************************
 ;��������� ������� �� ������� ��� ������� ������. 
 ; + ����
 ;**************** 26-01-2011 ********************************************************		

;***************************************************************************
	;������ ������ � �������� ����������
;**************************************************************************
        
 ; ��������� ��� �������
		clr     Bit_Mode_12x4
		clr     Bit_Mode_16x4
	    mov     PR_VIDELEN,#0; ���������� ����������� �����.
        lcall   RESP
;***********************
CALL TITLE ; ����� � �����

Menu_Regim_Cukl_1:

;����������, ���� ������ ������
      ;******* - �������� ������� ������********************************************
     ;*******��� ������� �� ������� �� ��� ��������� �� �������
 ;****** ����������� ���������� �������������� ������� ���������� ������. **************
;**************************************************************************************
		lcall   TTI_S
		
CHECK_12MS:
		jnb    S_12MS,GO_S_12MS	 ;���� ������� ������, �� �� ����� GO_S_12MS
        JMP CHECK_21MS			 ; ���� �� ������, �� � �������� ����. �������
		GO_S_12MS:				 
		JMP	DRAW_S_12MS			 ;������ ��� ������� �� ���
		;******************************
CHECK_21MS:
        jnb     S_21MS,GO_S_21MS
        JMP CHECK_300MS
		GO_S_21MS:
		JMP	DRAW_S_21MS
		;******************************
CHECK_300MS:
		jnb     S_300MS,GO_S_300MS
        JMP CHECK_1100MS
		GO_S_300MS:
		JMP	DRAW_S_300MS
        ;******************************
CHECK_1100MS: 
        jnb     S_1100MS,GO_S_1100MS
        JMP CHECK_OK
		GO_S_1100MS:
		JMP	DRAW_S_1100MS
		;******************************
CHECK_OK:
		jnb     S_OK,GO_S_OK
        JMP CHECK_SEL
		GO_S_OK:
		JMP	DRAW_S_OK
		;******************************
CHECK_SEL:
        jnb     S_SEL,GO_S_SEL
        JMP CHECK_POW_ON
		GO_S_SEL:
		JMP	DRAW_S_SEL
		;******************************
CHECK_POW_ON:
		jnb     POW_ON,GO_POW_ON
        JMP CHECK_POW_OFF
		GO_POW_ON:
		JMP	DRAW_POW_ON
		;******************************
CHECK_POW_OFF:
        jnb     POW_OFF,GO_POW_OFF
        JMP CHECK_TEST
		GO_POW_OFF:
		JMP	DRAW_POW_OFF
		;******************************
CHECK_TEST:
		jnb     TEST,GO_TEST
        JMP CHECK_RES
		GO_TEST:
		JMP	DRAW_TEST
		;******************************
CHECK_RES:
        jnb     RES,GO_RES
        JMP Menu_Regim_Cukl_002
		GO_RES:
		JMP	DRAW_RES
		;******************************


		
;����������, ���� ������ ����
      ;******* - �������� ���������� ������********************************************
     ;*******��� ������� �� ������� �� ��� ��������� �� �������
 ;****** ����������� ���������� �������������� ������� ���������� ������. **************
;**************************************************************************************
Menu_Regim_Cukl_002:
		
		lcall   TTI_G

CHECK_CHN_1_TEST_BTN:
        jnb     CHN_1,GO_G_CHN_1_TEST_BTN
        JMP CHECK_CHN_2_TEST_BTN
		GO_G_CHN_1_TEST_BTN:
		JMP	DRAW_CHN_1
		;******************************
CHECK_CHN_2_TEST_BTN:
		jnb     CHN_2,GO_G_CHN_2_TEST_BTN
        JMP CHECK_CHN_3_TEST_BTN
		GO_G_CHN_2_TEST_BTN:
		JMP	DRAW_CHN_2
        ;******************************
CHECK_CHN_3_TEST_BTN: 
		jnb     CHN_3,GO_G_CHN_3_TEST_BTN
        JMP CHECK_CHN_4_TEST_BTN
		GO_G_CHN_3_TEST_BTN:
		JMP	DRAW_CHN_3
		;******************************
CHECK_CHN_4_TEST_BTN:
		jnb     CHN_4,GO_G_CHN_4_TEST_BTN
        JMP CHECK_CHN_0_TEST_BTN
		GO_G_CHN_4_TEST_BTN:
		JMP	DRAW_CHN_4
		;******************************
CHECK_CHN_0_TEST_BTN:
		jnb     CHN_0,GO_G_CHN_0_TEST_BTN
        JMP Menu_Regim_Cukl_1
		GO_G_CHN_0_TEST_BTN:
		JMP	DRAW_CHN_0
		;****************************** 
 
 
        ljmp    Menu_Regim_Cukl_1    ; ���� ������ �� ������,
        ;*****************************; �� ��������� ����� ������� ������.
 ;******* ��������� ������� �������********************************************

DRAW_S_12MS:
       ;***********************
        mov     POZITION,#15
        mov     POZ_STR,#5
        mov     KOL_SIMV,#6
        mov     DPTR,#TEST1_BTN ; 12MS
        lcall   LcdStrWriteSt_Tabl
        ;*************************************************
 		JMP Menu_Regim_Cukl_1 ;RETURN TO CYCLE
        ;*************************************************

DRAW_S_21MS:
        ;*********************
        mov     POZITION,#15
        mov     POZ_STR,#5
        mov     KOL_SIMV,#6
        mov     DPTR,#TEST2_BTN ; 21MS
        lcall   LcdStrWriteSt_Tabl
        ;*************************************************
 		JMP Menu_Regim_Cukl_1 ;RETURN TO CYCLE
        ;*************************************************

DRAW_S_300MS:
        ;*********************
        mov     POZITION,#15
        mov     POZ_STR,#5
        mov     KOL_SIMV,#6
        mov     DPTR,#TEST3_BTN ; 300MS
        lcall   LcdStrWriteSt_Tabl
        ;*************************************************
 		JMP Menu_Regim_Cukl_1 ;RETURN TO CYCLE
        ;*************************************************

DRAW_S_1100MS:
        ;*********************
        mov     POZITION,#15
        mov     POZ_STR,#5
        mov     KOL_SIMV,#6
        mov     DPTR,#TEST4_BTN ; 1100MS
        lcall   LcdStrWriteSt_Tabl
        ;*************************************************
 		JMP Menu_Regim_Cukl_1 ;RETURN TO CYCLE
        ;*************************************************

DRAW_S_OK:
        ;*********************
        mov     POZITION,#15
        mov     POZ_STR,#5
        mov     KOL_SIMV,#6
        mov     DPTR,#TEST5_BTN ; OK
        lcall   LcdStrWriteSt_Tabl
        ;*************************************************
 		JMP Menu_Regim_Cukl_1 ;RETURN TO CYCLE
        ;*************************************************


DRAW_S_SEL:
        ;*********************
        mov     POZITION,#15
        mov     POZ_STR,#5
        mov     KOL_SIMV,#6
        mov     DPTR,#TEST6_BTN ; SEL
        lcall   LcdStrWriteSt_Tabl
        ;*************************************************
 		JMP Menu_Regim_Cukl_1 ;RETURN TO CYCLE
        ;*************************************************

DRAW_POW_ON:
        ;*********************
        mov     POZITION,#15
        mov     POZ_STR,#5
        mov     KOL_SIMV,#6
        mov     DPTR,#TEST7_BTN ; POW_ON
        lcall   LcdStrWriteSt_Tabl
        ;*************************************************
 		JMP Menu_Regim_Cukl_1 ;RETURN TO CYCLE
        ;*************************************************

DRAW_POW_OFF:
        ;*********************
        mov     POZITION,#15
        mov     POZ_STR,#5
        mov     KOL_SIMV,#6
        mov     DPTR,#TEST8_BTN ; POW_ON
        lcall   LcdStrWriteSt_Tabl
        ;*************************************************
 		JMP Menu_Regim_Cukl_1 ;RETURN TO CYCLE
        ;*************************************************


DRAW_TEST:
        ;*********************
        mov     POZITION,#15
        mov     POZ_STR,#5
        mov     KOL_SIMV,#6
        mov     DPTR,#TEST9_BTN ; TEST
        lcall   LcdStrWriteSt_Tabl
        ;*************************************************
 		JMP Menu_Regim_Cukl_1 ;RETURN TO CYCLE
        ;*************************************************


DRAW_RES:
        ;*********************
        mov     POZITION,#15
        mov     POZ_STR,#5
        mov     KOL_SIMV,#6
        mov     DPTR,#TEST10_BTN ; RES
        lcall   LcdStrWriteSt_Tabl
        ;*************************************************
 		JMP Menu_Regim_Cukl_1 ;RETURN TO CYCLE
        ;*************************************************


DRAW_CHN_1:
        ;*********************
        mov     POZITION,#15
        mov     POZ_STR,#6
        mov     KOL_SIMV,#1
        mov     DPTR,#TEST14_BTN ; '1'
        lcall   LcdStrWriteSt_Tabl
        ;*************************************************
 		JMP Menu_Regim_Cukl_1 ;RETURN TO CYCLE
        ;*************************************************


DRAW_CHN_2:
        ;*********************
        mov     POZITION,#15
        mov     POZ_STR,#6
        mov     KOL_SIMV,#1
        mov     DPTR,#TEST15_BTN ; '2'
        lcall   LcdStrWriteSt_Tabl
        ;*************************************************
 		JMP Menu_Regim_Cukl_1 ;RETURN TO CYCLE
        ;*************************************************

DRAW_CHN_3:
        ;*********************
        mov     POZITION,#15
        mov     POZ_STR,#6
        mov     KOL_SIMV,#1
        mov     DPTR,#TEST16_BTN ; '3'
        lcall   LcdStrWriteSt_Tabl
        ;*************************************************
 		JMP Menu_Regim_Cukl_1 ;RETURN TO CYCLE
        ;*************************************************

DRAW_CHN_4:
        ;*********************
        mov     POZITION,#15
        mov     POZ_STR,#6
        mov     KOL_SIMV,#1
        mov     DPTR,#TEST17_BTN ; '4'
        lcall   LcdStrWriteSt_Tabl
        ;*************************************************
 		JMP Menu_Regim_Cukl_1 ;RETURN TO CYCLE
        ;*************************************************

DRAW_CHN_0:
        ;*********************
        mov     POZITION,#15
        mov     POZ_STR,#6
        mov     KOL_SIMV,#1
        mov     DPTR,#TEST13_BTN ; '0'
        lcall   LcdStrWriteSt_Tabl
        ;*************************************************
 		JMP Menu_Regim_Cukl_1 ;RETURN TO CYCLE
        ;*************************************************
;********************************************
;        �������		
;********************************************		


TEST1_BTN: 		DB      '12MS  '			
TEST2_BTN: 		DB      '21MS  '
TEST3_BTN: 		DB      '300MS '
TEST4_BTN: 		DB      '1100MS' ;6
TEST5_BTN: 		DB		'OK    '
TEST6_BTN: 		DB      '����� '

TEST7_BTN: 		DB      '���   '
TEST8_BTN: 		DB      '����  '
TEST9_BTN: 		DB		'����  '
TEST10_BTN: 	DB      '����� '
TEST11_BTN: 	DB      '**���� ����������**' ;19
TEST12_BTN: 	DB      '---------------------'

TEST13_BTN: 	DB      '0'
TEST14_BTN: 	DB      '1'
TEST15_BTN: 	DB      '2'
TEST16_BTN: 	DB      '3'
TEST17_BTN: 	DB      '4'
TEST18_BTN: 	DB      '�����:'  ;6
TEST19_BTN: 	DB      '������� ����� ������'  ;20
TEST20_BTN: 	DB      '������ ������:'  ;14
;*********************************************

;//////////////////////////////////////////////////////////////////////
;                         ���������
;//////////////////////////////////////////////////////////////////////	

;======================================================
; ��������� ����� � ������
TITLE:
        ;*********************
        mov     POZITION,#0
        mov     POZ_STR,#0
        mov     KOL_SIMV,#19
        mov     DPTR,#TEST11_BTN ; **���� ����������**
        lcall   LcdStrWriteSt_Tabl

        ;*********************
        mov     POZITION,#0
        mov     POZ_STR,#2
        mov     KOL_SIMV,#20
        mov     DPTR,#TEST19_BTN ; ������� ����� ������
        lcall   LcdStrWriteSt_Tabl

        ;*********************
        mov     POZITION,#0
        mov     POZ_STR,#5
        mov     KOL_SIMV,#14
        mov     DPTR,#TEST20_BTN ; ������ ������:
        lcall   LcdStrWriteSt_Tabl

        mov     POZITION,#0
        mov     POZ_STR,#6
        mov     KOL_SIMV,#6
        mov     DPTR,#TEST18_BTN ; '�����:'
        lcall   LcdStrWriteSt_Tabl
		RET
;======================================================
