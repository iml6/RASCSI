//---------------------------------------------------------------------------
//
//  SCSI Target Emulator RaSCSI (*^..^*)
//  for Raspberry Pi
//
//  Powered by XM6 TypeG Technorogy.
//  Copyright (C) 2016-2017 GIMONS
//	[ �z�X�g�t�@�C���V�X�e�� �u���b�W�h���C�o ]
//
//---------------------------------------------------------------------------

#ifndef bridge_h
#define bridge_h

typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned long DWORD;
typedef int BOOL;

#if !defined(FALSE)
#define FALSE 0
#endif

#if !defined(TRUE)
#define TRUE 1
#endif

#define FASTCALL
#define ASSERT(x)

//---------------------------------------------------------------------------
//
//	�萔��`
//
//---------------------------------------------------------------------------
#define FILEPATH_MAX		_MAX_PATH
#define WINDRV_CLIPSIZE_MAX	0xC00000

//---------------------------------------------------------------------------
//
//	�X�e�[�^�X�R�[�h��`
//
//---------------------------------------------------------------------------
#define FS_INVALIDFUNC		0xFFFFFFFF	// �����ȃt�@���N�V�����R�[�h�����s����
#define FS_FILENOTFND		0xFFFFFFFE	// �w�肵���t�@�C����������Ȃ�
#define FS_DIRNOTFND		0xFFFFFFFD	// �w�肵���f�B���N�g����������Ȃ�
#define FS_OVEROPENED		0xFFFFFFFC	// �I�[�v�����Ă���t�@�C������������
#define FS_CANTACCESS		0xFFFFFFFB	// �f�B���N�g����{�����[�����x���̓A�N�Z�X�s��
#define FS_NOTOPENED		0xFFFFFFFA	// �w�肵���n���h���̓I�[�v������Ă��Ȃ�
#define FS_INVALIDMEM		0xFFFFFFF9	// �������Ǘ��̈悪�j�󂳂ꂽ
#define FS_OUTOFMEM			0xFFFFFFF8	// ���s�ɕK�v�ȃ��������Ȃ�
#define FS_INVALIDPTR		0xFFFFFFF7	// �����ȃ������Ǘ��|�C���^���w�肵��
#define FS_INVALIDENV		0xFFFFFFF6	// �s���Ȋ����w�肵��
#define FS_ILLEGALFMT		0xFFFFFFF5	// ���s�t�@�C���̃t�H�[�}�b�g���ُ�
#define FS_ILLEGALMOD		0xFFFFFFF4	// �I�[�v���̃A�N�Z�X���[�h���ُ�
#define FS_INVALIDPATH		0xFFFFFFF3	// �t�@�C�����̎w��Ɍ�肪����
#define FS_INVALIDPRM		0xFFFFFFF2	// �����ȃp�����[�^�ŃR�[������
#define FS_INVALIDDRV		0xFFFFFFF1	// �h���C�u�w��Ɍ�肪����
#define FS_DELCURDIR		0xFFFFFFF0	// �J�����g�f�B���N�g���͍폜�ł��Ȃ�
#define FS_NOTIOCTRL		0xFFFFFFEF	// IOCTRL�ł��Ȃ��f�o�C�X
#define FS_LASTFILE			0xFFFFFFEE	// ����ȏ�t�@�C����������Ȃ�
#define FS_CANTWRITE		0xFFFFFFED	// �w��̃t�@�C���͏������݂ł��Ȃ�
#define FS_DIRALREADY		0xFFFFFFEC	// �w��̃f�B���N�g���͊��ɓo�^����Ă���
#define FS_CANTDELETE		0xFFFFFFEB	// �t�@�C��������̂ō폜�ł��Ȃ�
#define FS_CANTRENAME		0xFFFFFFEA	// �t�@�C��������̂Ń��l�[���ł��Ȃ�
#define FS_DISKFULL			0xFFFFFFE9	// �f�B�X�N����t�Ńt�@�C�������Ȃ�
#define FS_DIRFULL			0xFFFFFFE8	// �f�B���N�g������t�Ńt�@�C�������Ȃ�
#define FS_CANTSEEK			0xFFFFFFE7	// �w��̈ʒu�ɂ̓V�[�N�ł��Ȃ�
#define FS_SUPERVISOR		0xFFFFFFE6	// �X�[�p�[�o�C�U��ԂŃX�[�p�o�C�U�w�肵��
#define FS_THREADNAME		0xFFFFFFE5	// �����X���b�h�������݂���
#define FS_BUFWRITE			0xFFFFFFE4	// �v���Z�X�ԒʐM�̃o�b�t�@�������݋֎~
#define FS_BACKGROUND		0xFFFFFFE3	// �o�b�N�O���E���h�v���Z�X���N���ł��Ȃ�
#define FS_OUTOFLOCK		0xFFFFFFE0	// ���b�N�̈悪����Ȃ�
#define FS_LOCKED			0xFFFFFFDF	// ���b�N����Ă��ăA�N�Z�X�ł��Ȃ�
#define FS_DRIVEOPENED		0xFFFFFFDE	// �w��̃h���C�u�̓n���h�����I�[�v������Ă���
#define FS_LINKOVER			0xFFFFFFDD	// �V���{���b�N�����N�l�X�g��16��𒴂���
#define FS_FILEEXIST		0xFFFFFFB0	// �t�@�C�������݂���

#define FS_FATAL_MEDIAOFFLINE	0xFFFFFFA3	// ���f�B�A�������Ă��Ȃ�
#define FS_FATAL_WRITEPROTECT	0xFFFFFFA2	// �������݋֎~�ᔽ
#define FS_FATAL_INVALIDCOMMAND	0xFFFFFFA1	// �s���ȃR�}���h�ԍ�
#define FS_FATAL_INVALIDUNIT	0xFFFFFFA0	// �s���ȃ��j�b�g�ԍ�

#define HUMAN68K_PATH_MAX	96	// Human68k�̃p�X�ő咷

//===========================================================================
//
/// Human68k ���O���
//
//===========================================================================
/// �t�@�C�������r�b�g
enum attribute_t {
	AT_READONLY	= 0x01,		// �ǂݍ��ݐ�p����
	AT_HIDDEN	= 0x02,		// �B������
	AT_SYSTEM	= 0x04,		// �V�X�e������
	AT_VOLUME	= 0x08,		// �{�����[�����x������
	AT_DIRECTORY= 0x10,		// �f�B���N�g������
	AT_ARCHIVE	= 0x20,		// �A�[�J�C�u����
	AT_ALL		= 0xFF,		// �S�Ă̑����r�b�g��1
};

/// �t�@�C���I�[�v�����[�h
enum open_t {
	OP_READ			= 0,	// �ǂݍ���
	OP_WRITE		= 1,	// ��������
	OP_FULL			= 2,	// �ǂݏ���
	OP_MASK			= 0x0F,	// ����p�}�X�N
	OP_SHARE_NONE	= 0x10,	// ���L�֎~
	OP_SHARE_READ	= 0x20,	// �ǂݍ��݋��L
	OP_SHARE_WRITE	= 0x30,	// �������݋��L
	OP_SHARE_FULL	= 0x40,	// �ǂݏ������L
	OP_SHARE_MASK	= 0x70,	// ���L����p�}�X�N
	OP_SPECIAL		= 0x100,// �����A�N�Z�X
};

/// �V�[�N���
enum seek_t {
	SK_BEGIN	= 0,		// �t�@�C���擪����
	SK_CURRENT	= 1,		// ���݈ʒu����
	SK_END		= 2,		// �t�@�C����������
};

/// ���f�B�A�o�C�g
enum media_t {
	MEDIA_2DD_10	= 0xE0,	// 2DD/10�Z�N�^
	MEDIA_1D_9		= 0xE5,	// 1D/9�Z�N�^
	MEDIA_2D_9		= 0xE6,	// 2D/9�Z�N�^
	MEDIA_1D_8		= 0xE7,	// 1D/8�Z�N�^
	MEDIA_2D_8		= 0xE8,	// 2D/8�Z�N�^
	MEDIA_2HT		= 0xEA,	// 2HT
	MEDIA_2HS		= 0xEB,	// 2HS
	MEDIA_2HDE		= 0xEC,	// 2DDE
	MEDIA_1DD_9		= 0xEE,	// 1DD/9�Z�N�^
	MEDIA_1DD_8		= 0xEF,	// 1DD/8�Z�N�^
	MEDIA_MANUAL	= 0xF1,	// �����[�g�h���C�u (�蓮�C�W�F�N�g)
	MEDIA_REMOVABLE	= 0xF2,	// �����[�g�h���C�u (�����[�o�u��)
	MEDIA_REMOTE	= 0xF3,	// �����[�g�h���C�u
	MEDIA_DAT		= 0xF4,	// SCSI-DAT
	MEDIA_CDROM		= 0xF5,	// SCSI-CDROM
	MEDIA_MO		= 0xF6,	// SCSI-MO
	MEDIA_SCSI_HD	= 0xF7,	// SCSI-HD
	MEDIA_SASI_HD	= 0xF8,	// SASI-HD
	MEDIA_RAMDISK	= 0xF9,	// RAM�f�B�X�N
	MEDIA_2HQ		= 0xFA,	// 2HQ
	MEDIA_2DD_8		= 0xFB,	// 2DD/8�Z�N�^
	MEDIA_2DD_9		= 0xFC,	// 2DD/9�Z�N�^
	MEDIA_2HC		= 0xFD,	// 2HC
	MEDIA_2HD		= 0xFE,	// 2HD
};

/// namests�\����
typedef struct {
	BYTE wildcard;			// ���C���h�J�[�h������
	BYTE drive;				// �h���C�u�ԍ�
	BYTE path[65];			// �p�X(�T�u�f�B���N�g��+/)
	BYTE name[8];			// �t�@�C���� (PADDING 0x20)
	BYTE ext[3];			// �g���q (PADDING 0x20)
	BYTE add[10];			// �t�@�C�����ǉ� (PADDING 0x00)
} namests_t;

/// files�\����
typedef struct {
	BYTE fatr;				// + 0 �������鑮��			�Ǎ���p
	BYTE pad1[3];			// padding
//		BYTE drive;			// + 1 �h���C�u�ԍ�			�Ǎ���p
	DWORD sector;			// + 2 �f�B���N�g���̃Z�N�^	DOS _FILES�擪�A�h���X�ő�p
//		WORD cluster;		// + 6 �f�B���N�g���̃N���X�^	�ڍוs�� (���g�p)
	WORD offset;			// + 8 �f�B���N�g���G���g��	������p
//		BYTE name[8];		// +10 ��Ɨp�t�@�C����		�Ǎ���p (���g�p)
//		BYTE ext[3];		// +18 ��Ɨp�g���q			�Ǎ���p (���g�p)
	BYTE attr;				// +21 �t�@�C������			������p
	BYTE pad2;				// padding
	WORD time;				// +22 �ŏI�ύX����			������p
	WORD date;				// +24 �ŏI�ύX����			������p
	DWORD size;				// +26 �t�@�C���T�C�Y			������p
	BYTE full[23];			// +30 �t���t�@�C����			������p
	BYTE pad3;				// padding
} files_t;

/// FCB�\����
typedef struct {
//		BYTE pad00[6];		// + 0�`+ 5	(���g�p)
	DWORD fileptr;			// + 6�`+ 9	�t�@�C���|�C���^
//		BYTE pad01[4];		// +10�`+13	(���g�p)
	WORD mode;				// +14�`+15	�I�[�v�����[�h
//		BYTE pad02[16];		// +16�`+31	(���g�p)
//		DWORD zero;			// +32�`+35	�I�[�v���̂Ƃ�0���������܂�Ă��� (���g�p)
//		BYTE name[8];		// +36�`+43	�t�@�C���� (PADDING 0x20) (���g�p)
//		BYTE ext[3];		// +44�`+46	�g���q (PADDING 0x20) (���g�p)
	BYTE attr;				// +47		�t�@�C������
	BYTE pad;				// padding
//		BYTE add[10];		// +48�`+57	�t�@�C�����ǉ� (PADDING 0x00) (���g�p)
	WORD time;				// +58�`+59	�ŏI�ύX����
	WORD date;				// +60�`+61	�ŏI�ύX����
//		WORD cluster;		// +62�`+63	�N���X�^�ԍ� (���g�p)
	DWORD size;				// +64�`+67	�t�@�C���T�C�Y
//		BYTE pad03[28];		// +68�`+95	FAT�L���b�V�� (���g�p)
} fcb_t;

/// capacity�\����
typedef struct {
	WORD freearea;			// + 0	�g�p�\�ȃN���X�^��
	WORD clusters;			// + 2	���N���X�^��
	WORD sectors;			// + 4	�N���X�^������̃Z�N�^��
	WORD bytes;				// + 6	�Z�N�^������̃o�C�g��
} capacity_t;

/// ctrldrive�\����
typedef struct {
	BYTE status;			// +13	���
	BYTE pad[3];			// padding
} ctrldrive_t;

/// DPB�\����
typedef struct {
	WORD sector_size;		// + 0	1�Z�N�^����̃o�C�g��
	BYTE cluster_size;		// + 2	1�N���X�^����̃Z�N�^��-1
	BYTE shift;				// + 3	�N���X�^���Z�N�^�̃V�t�g��
	WORD fat_sector;		// + 4	FAT�̐擪�Z�N�^�ԍ�
	BYTE fat_max;			// + 6	FAT�̈�̌�
	BYTE fat_size;			// + 7	FAT�̐�߂�Z�N�^��(���ʕ�������)
	WORD file_max;			// + 8	���[�g�f�B���N�g���ɓ���t�@�C���̌�
	WORD data_sector;		// +10	�f�[�^�̈�̐擪�Z�N�^�ԍ�
	WORD cluster_max;		// +12	���N���X�^��+1
	WORD root_sector;		// +14	���[�g�f�B���N�g���̐擪�Z�N�^�ԍ�
//		DWORD driverentry;	// +16	�f�o�C�X�h���C�o�ւ̃|�C���^ (���g�p)
	BYTE media;				// +20	���f�B�A���ʎq
//		BYTE flag;			// +21	DPB�g�p�t���O (���g�p)
	BYTE pad;				// padding
} dpb_t;

/// �f�B���N�g���G���g���\����
typedef struct {
	BYTE name[8];			// + 0	�t�@�C���� (PADDING 0x20)
	BYTE ext[3];			// + 8	�g���q (PADDING 0x20)
	BYTE attr;				// +11	�t�@�C������
	BYTE add[10];			// +12	�t�@�C�����ǉ� (PADDING 0x00)
	WORD time;				// +22	�ŏI�ύX����
	WORD date;				// +24	�ŏI�ύX����
	WORD cluster;			// +26	�N���X�^�ԍ�
	DWORD size;				// +28	�t�@�C���T�C�Y
} dirent_t;

/// IOCTRL�p�����[�^���p��
typedef union {
	BYTE buffer[8];			// �o�C�g�P�ʂł̃A�N�Z�X
	DWORD param;			// �p�����[�^(�擪4�o�C�g)
	WORD media;				// ���f�B�A�o�C�g(�擪2�o�C�g)
} ioctrl_t;

/// �R�}���h���C�������\����
typedef struct {
	BYTE buf[256];			// �R�}���h���C������
} argument_t;

#endif	// bridge_h