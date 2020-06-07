#include "stdafx.h"
#include "image.h"

image::image() : _imageInfo(NULL), _fileName(NULL), _blendImage(NULL)
{
}
image::~image()
{
}

// �� ��Ʈ�� �ʱ�ȭ
HRESULT image::init(int width, int height)
{
	// ���ʱ�ȭ ������ (�̹��� ������ ���� ��� �ִٸ� �������ؼ� �����ϰ� �ʱ�ȭ ���� ��)
	if (_imageInfo != NULL) this->release();

	// DC ��������
	HDC hdc = GetDC(_hWnd);

	// �̹��� ���� ����ü ���� ���� �� �ʱ�ȭ �ϱ�
	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_EMPTY;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, width, height);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->width = width;
	_imageInfo->height = height;

	// ���� �̸�
	_fileName = NULL;

	// ����Ű �÷� ����
	_isTrans = FALSE;
	_transColor = RGB(0, 0, 0);

	// ���ҽ� ��� ���� �������� ��� �ٷ� ����
	if (_imageInfo->hBit == NULL)
	{
		this->release();
		return E_FAIL;
	}

	// DC �����ϱ�
	ReleaseDC(_hWnd, hdc);

	return S_OK;
}

// �̹��� ���Ϸ� �ʱ�ȭ
HRESULT image::init(const char * fileName, int width, int height, bool isTrans, COLORREF transColor)
{
	// ���ʱ�ȭ ������ (�̹��� ������ ���� ��� �ִٸ� �������ؼ� �����ϰ� �ʱ�ȭ ���� ��)
	if (_imageInfo != NULL) this->release();

	// DC ��������
	HDC hdc = GetDC(_hWnd);

	// �̹��� ���� ����ü ���� ���� �� �ʱ�ȭ
	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_FILE;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->width = width;
	_imageInfo->height = height;

	// ���� �̸�
	int len = strlen(fileName);
	_fileName = new char[len + 1];
	strcpy_s(_fileName, len + 1, fileName);

	// ����Ű �÷� ����
	_isTrans = isTrans;
	_transColor = transColor;

	// ���ҽ� ��� ���� �������� ��� �ٷ� ����
	if (_imageInfo->hBit == NULL)
	{
		this->release();
		return E_FAIL;
	}

	// DC �����ϱ�
	ReleaseDC(_hWnd, hdc);

	return S_OK;
}
HRESULT image::init(const char* fileName, float x, float y, int width, int height, bool isTrans, COLORREF transColor)
{
	// ���ʱ�ȭ ������ (�̹��� ������ ���� ��� �ִٸ� �������ؼ� �����ϰ� �ʱ�ȭ ���� ��)
	if (_imageInfo != NULL) this->release();

	// DC ��������
	HDC hdc = GetDC(_hWnd);

	// �̹��� ���� ����ü ���� ���� �� �ʱ�ȭ
	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_FILE;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->x = x;
	_imageInfo->y = y;
	_imageInfo->width = width;
	_imageInfo->height = height;

	// ���� �̸�
	int len = strlen(fileName);
	_fileName = new char[len + 1];
	strcpy_s(_fileName, len + 1, fileName);

	// ����Ű �÷� ����
	_isTrans = isTrans;
	_transColor = transColor;

	// ���ҽ� ��� ���� �������� ��� �ٷ� ����
	if (_imageInfo->hBit == NULL)
	{
		this->release();
		return E_FAIL;
	}

	// DC �����ϱ�
	ReleaseDC(_hWnd, hdc);

	return S_OK;
}
HRESULT image::init(const char* fileName, int width, int height, int frameX, int frameY, bool isTrans, COLORREF transColor)
{
	// ���ʱ�ȭ ������ (�̹��� ������ ���� ��� �ִٸ� �������ؼ� �����ϰ� �ʱ�ȭ ���� ��)
	if (_imageInfo != NULL) this->release();

	// DC ��������
	HDC hdc = GetDC(_hWnd);

	// �̹��� ���� ����ü ���� ���� �� �ʱ�ȭ
	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_FILE;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->width = width;
	_imageInfo->height = height;
	_imageInfo->currentFrameX = 0;
	_imageInfo->currentFrameY = 0;
	_imageInfo->maxFrameX = frameX - 1;
	_imageInfo->maxFrameY = frameY - 1;
	_imageInfo->frameWidth = width / frameX;
	_imageInfo->frameHeight = height / frameY;

	// ���� �̸�
	int len = strlen(fileName);
	_fileName = new char[len + 1];
	strcpy_s(_fileName, len + 1, fileName);

	// ����Ű �÷� ����
	_isTrans = isTrans;
	_transColor = transColor;

	// ���ҽ� ��� ���� �������� ��� �ٷ� ����
	if (_imageInfo->hBit == NULL)
	{
		this->release();
		return E_FAIL;
	}

	// DC �����ϱ�
	ReleaseDC(_hWnd, hdc);

	return S_OK;
}
HRESULT image::init(const char* fileName, float x, float y, int width, int height, int frameX, int frameY, bool isTrans, COLORREF transColor)
{
	// ���ʱ�ȭ ������ (�̹��� ������ ���� ��� �ִٸ� �������ؼ� �����ϰ� �ʱ�ȭ ���� ��)
	if (_imageInfo != NULL) this->release();

	// DC ��������
	HDC hdc = GetDC(_hWnd);

	// �̹��� ���� ����ü ���� ���� �� �ʱ�ȭ
	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_FILE;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->x = x;
	_imageInfo->y = y;
	_imageInfo->width = width;
	_imageInfo->height = height;
	_imageInfo->currentFrameX = 0;
	_imageInfo->currentFrameY = 0;
	_imageInfo->maxFrameX = frameX - 1;
	_imageInfo->maxFrameY = frameY - 1;
	_imageInfo->frameWidth = width / frameX;
	_imageInfo->frameHeight = height / frameY;

	// ���� �̸�
	int len = strlen(fileName);
	_fileName = new char[len + 1];
	strcpy_s(_fileName, len + 1, fileName);

	// ����Ű �÷� ����
	_isTrans = isTrans;
	_transColor = transColor;

	// ���ҽ� ��� ���� �������� ��� �ٷ� ����
	if (_imageInfo->hBit == NULL)
	{
		this->release();
		return E_FAIL;
	}

	// DC �����ϱ�
	ReleaseDC(_hWnd, hdc);

	return S_OK;
}

// ���� ���� �ʱ�ȭ
HRESULT image::initForAlphaBlend()
{
	// DC ��������
	HDC hdc = GetDC(_hWnd);

	// ���� ���� �ɼ� �ʱ�ȭ
	// BlendOp => ����� AC_SRC_OVER�� ��� ����
	// BlendFlags => ������� �ʴ� ����̹Ƿ� 0 ����
	// AlphaFormat => 24bit ���� 0, 32bit ���� AC_SRC_ALPHA ���
	// SourceConstantAlpha => ��Ʈ�� ���� ����
	_blendFunc.BlendOp = AC_SRC_OVER;
	_blendFunc.BlendFlags = 0;
	_blendFunc.AlphaFormat = 0;
	_blendFunc.SourceConstantAlpha = 128; // 0 ~ 255, 255�϶� ��������

	// �̹��� ���� ����ü ���� ������ �ʱ�ȭ
	_blendImage = new IMAGE_INFO;
	_blendImage->loadType = LOAD_FILE;
	_blendImage->hMemDC = CreateCompatibleDC(hdc);
	_blendImage->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, _imageInfo->width, _imageInfo->height);
	_blendImage->hOBit = (HBITMAP)SelectObject(_blendImage->hMemDC, _blendImage->hBit);
	_blendImage->width = WINSIZEX;
	_blendImage->height = WINSIZEY;

	// DC �����ϱ�
	ReleaseDC(_hWnd, hdc);
	return S_OK;
}

void image::release()
{
	// �̹��� ������ ���� �ִٸ� ���� ��ų ��
	if (_imageInfo)
	{
		// �̹��� ����
		SelectObject(_imageInfo->hMemDC, _imageInfo->hOBit);
		DeleteObject(_imageInfo->hBit);
		DeleteDC(_imageInfo->hMemDC);
		
		// ������ ����
		SAFE_DELETE(_imageInfo);
		SAFE_DELETE_ARRAY(_fileName);
		
		// ���� �÷�Ű �ʱ�ȭ
		_isTrans = FALSE;
		_transColor = RGB(0, 0, 0);
	}
}

// ���� (���� ���ϴ� ��ǥ�� ���, �Ϲ������� RECT�� LT��ǥ�� �̹����� ����)
void image::render(HDC hdc, int destX, int destY)
{
	if (_isTrans)	// ���� ���ְ� ���
	{
		// GdiTransparentBlt : ��Ʈ���� Ư�������� �����ϰ� ��Ӻ��� ���ִ� �Լ�
		GdiTransparentBlt(
			hdc,				// ������ ����� DC
			destX,				// ������ ��ǥ ����X
			destY,				// ������ ��ǥ ����Y
			_imageInfo->width,	// ������ �̹��� ����ũ��
			_imageInfo->height,	// ������ �̹��� ����ũ��
			_imageInfo->hMemDC,	// ����� ��� DC
			0, 0,				// ����� ����� ��������
			_imageInfo->width,	// ���� ���� ����ũ��
			_imageInfo->height,	// ���� ���� ����ũ��
			_transColor);		// ������ �� ������ ���� (�Ϲ������� ����Ÿ���� ����)
	}
	else	// ���� �̹��� �״�� ���
	{
		// BitBlt : DC���� �������� ��Ӻ��� ���ִ� �Լ�
		// �޸�DC -> ȭ��DC�� ����
		BitBlt(hdc, destX, destY, _imageInfo->width, _imageInfo->height, _imageInfo->hMemDC, 0, 0, SRCCOPY);
	}
}

// ���� (���� ���ϴ� ��ǥ�� ���ϴ� ũ�⸸ŭ �߶� ���)
void image::render(HDC hdc, int destX, int destY, int sourceX, int sourceY, int sourceWidth, int sourceHeight)
{
	if (_isTrans)	// ���� ���ְ� ���
	{
		// GdiTransparentBlt : ��Ʈ���� Ư�������� �����ϰ� ��Ӻ��� ���ִ� �Լ�
		GdiTransparentBlt(
			hdc,				// ������ ����� DC
			destX,				// ������ ��ǥ ����X
			destY,				// ������ ��ǥ ����Y
			sourceWidth,		// ������ �̹��� ����ũ��
			sourceHeight,		// ������ �̹��� ����ũ��
			_imageInfo->hMemDC,	// ����� ��� DC
			sourceX, sourceY,	// ����� ����� ��������
			sourceWidth,		// ���� ���� ����ũ��
			sourceHeight,		// ���� ���� ����ũ��
			_transColor);		// ������ �� ������ ���� (�Ϲ������� ����Ÿ���� ����)
	}
	else	// ���� �̹��� �״�� ���
	{
		// BitBlt : DC���� �������� ��Ӻ��� ���ִ� �Լ�
		// �޸�DC -> ȭ��DC�� ����
		BitBlt(hdc, destX, destY, sourceWidth, sourceHeight, _imageInfo->hMemDC, sourceX, sourceY, SRCCOPY);
	}
}

// ���� ����
void image::alphaRender(HDC hdc, BYTE alpha)
{
	// ���� ������ ó�� ����ϴ°�?
	// ���� ������ ����� �� �ֵ��� �ʱ�ȭ
	if (!_blendImage) this->initForAlphaBlend();

	// ���İ� �ʱ�ȭ
	_blendFunc.SourceConstantAlpha = alpha;

	if (_isTrans)	// ���� ���ְ� ���
	{
		// 1. ���� ȭ�� DC�� ������ ���� �̹����� ����
		// 2. �̹��� �޸� DC�� ������ ���� �� ���� �̹����� ����
		// 3. ���� �̹����� ȭ�� DC�� ���� (���� ����)

		// 1)
		BitBlt(_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, hdc, 0, 0, SRCCOPY);

		// 2)
		GdiTransparentBlt(
			_blendImage->hMemDC,	// ������ ����� DC
			0,						// ������ ��ǥ ����X
			0,						// ������ ��ǥ ����Y
			_imageInfo->width,		// ������ �̹��� ���� ũ��
			_imageInfo->height,		// ������ �̹��� ���� ũ��
			_imageInfo->hMemDC,		// ����� ��� DC
			0, 0,					// ����� ����� ��������
			_imageInfo->width,		// ���� ���� ���� ũ��
			_imageInfo->height,		// ���� ���� ���� ũ��
			_transColor);			// �����Ҷ� ������ ���� (�Ϲ������� ����Ÿ)

		// 3)
		GdiAlphaBlend(hdc, 0, 0, _imageInfo->width, _imageInfo->height, _blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _blendFunc);
	}
	else	// ���� �̹��� �״�� ���
	{
		GdiAlphaBlend(hdc, 0, 0, _imageInfo->width, _imageInfo->height, _imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _blendFunc);
	}
}
void image::alphaRender(HDC hdc, int destX, int destY, BYTE alpha)
{
	// ���� ������ ó�� ����ϴ°�?
	// ���� ������ ����� �� �ֵ��� �ʱ�ȭ
	if (!_blendImage) this->initForAlphaBlend();

	// ���İ� �ʱ�ȭ
	_blendFunc.SourceConstantAlpha = alpha;

	if (_isTrans)	// ���� ���ְ� ���
	{
		// 1. ���� ȭ�� DC�� ������ ���� �̹����� ����
		// 2. �̹��� �޸� DC�� ������ ���� �� ���� �̹����� ����
		// 3. ���� �̹����� ȭ�� DC�� ���� (���� ����)

		// 1)
		BitBlt(_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, hdc, destX, destY, SRCCOPY);

		// 2)
		GdiTransparentBlt(
			_blendImage->hMemDC,	// ������ ����� DC
			0,						// ������ ��ǥ ����X
			0,						// ������ ��ǥ ����Y
			_imageInfo->width,		// ������ �̹��� ���� ũ��
			_imageInfo->height,		// ������ �̹��� ���� ũ��
			_imageInfo->hMemDC,		// ����� ��� DC
			0, 0,					// ����� ����� ��������
			_imageInfo->width,		// ���� ���� ���� ũ��
			_imageInfo->height,		// ���� ���� ���� ũ��
			_transColor);			// �����Ҷ� ������ ���� (�Ϲ������� ����Ÿ)

		// 3)
		GdiAlphaBlend(hdc, destX, destY, _imageInfo->width, _imageInfo->height, _blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _blendFunc);
	}
	else	// ���� �̹��� �״�� ���
	{
		GdiAlphaBlend(hdc, destX, destY, _imageInfo->width, _imageInfo->height, _imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _blendFunc);
	}
}
void image::alphaRender(HDC hdc, int destX, int destY, int sourceX, int sourceY, int sourceWidth, int sourceHeight, BYTE alpha)
{
	// ���� ������ ó�� ����ϴ°�?
	// ���� ������ ����� �� �ֵ��� �ʱ�ȭ
	if (!_blendImage) this->initForAlphaBlend();

	// ���İ� �ʱ�ȭ
	_blendFunc.SourceConstantAlpha = alpha;

	if (_isTrans)	// ���� ���ְ� ���
	{
		// 1. ���� ȭ�� DC�� ������ ���� �̹����� ����
		// 2. �̹��� �޸� DC�� ������ ���� �� ���� �̹����� ����
		// 3. ���� �̹����� ȭ�� DC�� ���� (���� ����)

		// 1)
		BitBlt(_blendImage->hMemDC, sourceX, sourceY, sourceWidth, sourceHeight, hdc, destX, destY, SRCCOPY);

		// 2)
		GdiTransparentBlt(
			_blendImage->hMemDC,	// ������ ����� DC
			0,						// ������ ��ǥ ����X
			0,						// ������ ��ǥ ����Y
			_imageInfo->width,		// ������ �̹��� ���� ũ��
			_imageInfo->height,		// ������ �̹��� ���� ũ��
			_imageInfo->hMemDC,		// ����� ��� DC
			0, 0,					// ����� ����� ��������
			_imageInfo->width,		// ���� ���� ���� ũ��
			_imageInfo->height,		// ���� ���� ���� ũ��
			_transColor);			// �����Ҷ� ������ ���� (�Ϲ������� ����Ÿ)

		// 3)
		GdiAlphaBlend(hdc, destX, destY, sourceWidth, sourceHeight, _blendImage->hMemDC, sourceX, sourceY, sourceWidth, sourceHeight, _blendFunc);
	}
	else	// ���� �̹��� �״�� ���
	{
		GdiAlphaBlend(hdc, destX, destY, sourceWidth, sourceHeight, _imageInfo->hMemDC, sourceX, sourceY, sourceWidth, sourceHeight, _blendFunc);
	}
}

// ������ ����
void image::frameRender(HDC hdc, int destX, int destY)
{
	if (_isTrans)	// ���� ���ְ� ���
	{
		// GdiTransparentBlt : ��Ʈ���� Ư�������� �����ϰ� ��Ӻ��� ���ִ� �Լ�
		GdiTransparentBlt(
			hdc,						// ������ ����� DC
			destX,						// ������ ��ǥ ����X
			destY,						// ������ ��ǥ ����Y
			_imageInfo->frameWidth,		// ������ �̹��� ���� ũ��
			_imageInfo->frameHeight,	// ������ �̹��� ���� ũ��
			_imageInfo->hMemDC,			// ����� ��� DC
			_imageInfo->currentFrameX * _imageInfo->frameWidth,			// ����� ����� ���� ���� X��ǥ
			_imageInfo->currentFrameY * _imageInfo->frameHeight,		// ����� ����� ���� ���� Y��ǥ
			_imageInfo->frameWidth,		// ���� ���� ���� ũ��
			_imageInfo->frameHeight,	// ���� ���� ���� ũ��
			_transColor);				// �����Ҷ� ������ ����(�Ϲ������� ����Ÿ)
	}
	else	//���� �̹��� �״�� ���
	{
		// BitBlt : DC���� �������� ��Ӻ��� ���ִ� �Լ�
		// �޸�DC -> ȭ��DC�� ����
		BitBlt(hdc, destX, destY, _imageInfo->frameWidth, _imageInfo->frameHeight,
			_imageInfo->hMemDC,
			_imageInfo->currentFrameX * _imageInfo->frameWidth,
			_imageInfo->currentFrameY * _imageInfo->frameHeight, SRCCOPY);
	}
}
void image::frameRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY)
{
	// �̹��� ����ó��
	// int hp;
	// if(hp < 0) hp = 0;
	_imageInfo->currentFrameX = currentFrameX;
	_imageInfo->currentFrameY = currentFrameY;
	if (currentFrameX > _imageInfo->maxFrameX)
	{
		_imageInfo->currentFrameX = _imageInfo->maxFrameX;
	}
	if (currentFrameY > _imageInfo->maxFrameY)
	{
		_imageInfo->currentFrameY = _imageInfo->maxFrameY;
	}

	if (_isTrans)	// ���� ���ְ� ���
	{
		// GdiTransparentBlt : ��Ʈ���� Ư�������� �����ϰ� ��Ӻ��� ���ִ� �Լ�
		GdiTransparentBlt(
			hdc,						// ������ ����� DC
			destX,						// ������ ��ǥ ����X
			destY,						// ������ ��ǥ ����Y
			_imageInfo->frameWidth,		// ������ �̹��� ���� ũ��
			_imageInfo->frameHeight,	// ������ �̹��� ���� ũ��
			_imageInfo->hMemDC,			// ����� ��� DC
			_imageInfo->currentFrameX * _imageInfo->frameWidth,			// ����� ����� ���� ���� X��ǥ
			_imageInfo->currentFrameY * _imageInfo->frameHeight,		// ����� ����� ���� ���� Y��ǥ
			_imageInfo->frameWidth,		// ���� ���� ���� ũ��
			_imageInfo->frameHeight,	// ���� ���� ���� ũ��
			_transColor);				// �����Ҷ� ������ ����(�Ϲ������� ����Ÿ)
	}
	else	//���� �̹��� �״�� ���
	{
		// BitBlt : DC���� �������� ��Ӻ��� ���ִ� �Լ�
		// �޸�DC -> ȭ��DC�� ����
		BitBlt(hdc, destX, destY, _imageInfo->frameWidth, _imageInfo->frameHeight,
			_imageInfo->hMemDC,
			_imageInfo->currentFrameX * _imageInfo->frameWidth,
			_imageInfo->currentFrameY * _imageInfo->frameHeight, SRCCOPY);
	}
}
void image::frameRender(HDC hdc, int destX, int destY, int sourceX, int sourceY, int sourceWidth, int sourceHeight, int frameX, int frameY)
{
	_imageInfo->maxFrameX = frameX - 1;
	_imageInfo->maxFrameY = frameY - 1;
	_imageInfo->frameWidth = _imageInfo->width / frameX;
	_imageInfo->frameHeight = _imageInfo->height / frameY;

	if (_isTrans)	// ���� ���ְ� ���
	{
		// GdiTransparentBlt : ��Ʈ���� Ư�������� �����ϰ� ��Ӻ��� ���ִ� �Լ�
		GdiTransparentBlt(
			hdc,						// ������ ����� DC
			destX,						// ������ ��ǥ ����X
			destY,						// ������ ��ǥ ����Y
			sourceWidth,				// ������ �̹��� ���� ũ��
			sourceHeight,				// ������ �̹��� ���� ũ��
			_imageInfo->hMemDC,			// ����� ��� DC
			sourceX + (_imageInfo->currentFrameX * sourceWidth),			// ����� ����� ���� ���� X��ǥ
			sourceY + (_imageInfo->currentFrameY * sourceHeight),			// ����� ����� ���� ���� Y��ǥ
			sourceWidth,				// ���� ���� ���� ũ��
			sourceHeight,				// ���� ���� ���� ũ��
			_transColor);				// �����Ҷ� ������ ����(�Ϲ������� ����Ÿ)
	}
	else	//���� �̹��� �״�� ���
	{
		// BitBlt : DC���� �������� ��Ӻ��� ���ִ� �Լ�
		// �޸�DC -> ȭ��DC�� ����
		BitBlt(hdc, destX, destY, sourceWidth, sourceHeight, _imageInfo->hMemDC,
			sourceX + (_imageInfo->currentFrameX * sourceWidth),
			sourceY + (_imageInfo->currentFrameY * sourceHeight), SRCCOPY);
	}
}
void image::frameRender(HDC hdc, int destX, int destY, int sourceX, int sourceY, int sourceWidth, int sourceHeight, int frameX, int frameY, int currentFrameX, int currentFrameY)
{
	_imageInfo->maxFrameX = frameX - 1;
	_imageInfo->maxFrameY = frameY - 1;
	_imageInfo->frameWidth = _imageInfo->width / frameX;
	_imageInfo->frameHeight = _imageInfo->height / frameY;

	// �̹��� ����ó��
	// int hp;
	// if(hp < 0) hp = 0;
	_imageInfo->currentFrameX = currentFrameX;
	_imageInfo->currentFrameY = currentFrameY;
	if (currentFrameX > _imageInfo->maxFrameX)
	{
		_imageInfo->currentFrameX = _imageInfo->maxFrameX;
	}
	if (currentFrameY > _imageInfo->maxFrameY)
	{
		_imageInfo->currentFrameY = _imageInfo->maxFrameY;
	}

	if (_isTrans)	// ���� ���ְ� ���
	{
		// GdiTransparentBlt : ��Ʈ���� Ư�������� �����ϰ� ��Ӻ��� ���ִ� �Լ�
		GdiTransparentBlt(
			hdc,						// ������ ����� DC
			destX,						// ������ ��ǥ ����X
			destY,						// ������ ��ǥ ����Y
			sourceWidth,				// ������ �̹��� ���� ũ��
			sourceHeight,				// ������ �̹��� ���� ũ��
			_imageInfo->hMemDC,			// ����� ��� DC
			sourceX + (_imageInfo->currentFrameX * sourceWidth),			// ����� ����� ���� ���� X��ǥ
			sourceY + (_imageInfo->currentFrameY * sourceHeight),			// ����� ����� ���� ���� Y��ǥ
			sourceWidth,				// ���� ���� ���� ũ��
			sourceHeight,				// ���� ���� ���� ũ��
			_transColor);				// �����Ҷ� ������ ����(�Ϲ������� ����Ÿ)
	}
	else	//���� �̹��� �״�� ���
	{
		// BitBlt : DC���� �������� ��Ӻ��� ���ִ� �Լ�
		// �޸�DC -> ȭ��DC�� ����
		BitBlt(hdc, destX, destY, sourceWidth, sourceHeight, _imageInfo->hMemDC,
			sourceX + (_imageInfo->currentFrameX * sourceWidth),
			sourceY + (_imageInfo->currentFrameY * sourceHeight), SRCCOPY);
	}
}
void image::frameAlphaRender(HDC hdc, int destX, int destY, int sourceX, int sourceY, int sourceWidth, int sourceHeight, int frameX, int frameY, BYTE alpha)
{
	// ���� ������ ó�� ����ϴ°�?
	// ���� ������ ����� �� �ֵ��� �ʱ�ȭ
	if (!_blendImage) this->initForAlphaBlend();

	// ���İ� �ʱ�ȭ
	_blendFunc.SourceConstantAlpha = alpha;

	_imageInfo->maxFrameX = frameX - 1;
	_imageInfo->maxFrameY = frameY - 1;
	_imageInfo->frameWidth = _imageInfo->width / frameX;
	_imageInfo->frameHeight = _imageInfo->height / frameY;

	/*
	if (_isTrans)	// ���� ���ְ� ���
	{
		GdiTransparentBlt(
			hdc,						// ������ ����� DC
			destX,						// ������ ��ǥ ����X
			destY,						// ������ ��ǥ ����Y
			sourceWidth,				// ������ �̹��� ���� ũ��
			sourceHeight,				// ������ �̹��� ���� ũ��
			_imageInfo->hMemDC,			// ����� ��� DC
			sourceX + (_imageInfo->currentFrameX * sourceWidth),			// ����� ����� ���� ���� X��ǥ
			sourceY + (_imageInfo->currentFrameY * sourceHeight),			// ����� ����� ���� ���� Y��ǥ
			sourceWidth,				// ���� ���� ���� ũ��
			sourceHeight,				// ���� ���� ���� ũ��
			_transColor);				// �����Ҷ� ������ ����(�Ϲ������� ����Ÿ)
	}
	else	//���� �̹��� �״�� ���
	{
		BitBlt(hdc, destX, destY, sourceWidth, sourceHeight, _imageInfo->hMemDC,
			sourceX + (_imageInfo->currentFrameX * sourceWidth),
			sourceY + (_imageInfo->currentFrameY * sourceHeight), SRCCOPY);
	}
	*/

	if (_isTrans)	// ���� ���ְ� ���
	{
		// 1)
		BitBlt(_blendImage->hMemDC, sourceX, sourceY, sourceWidth, sourceHeight, hdc, destX, destY, SRCCOPY);

		// 2)
		GdiTransparentBlt(
			_blendImage->hMemDC,	// ������ ����� DC
			0,						// ������ ��ǥ ����X
			0,						// ������ ��ǥ ����Y
			_imageInfo->width,		// ������ �̹��� ���� ũ��
			_imageInfo->height,		// ������ �̹��� ���� ũ��
			_imageInfo->hMemDC,		// ����� ��� DC
			0, 0,					// ����� ����� ��������
			_imageInfo->width,		// ���� ���� ���� ũ��
			_imageInfo->height,		// ���� ���� ���� ũ��
			_transColor);			// �����Ҷ� ������ ���� (�Ϲ������� ����Ÿ)

		// 3)
		GdiAlphaBlend(hdc, destX, destY, sourceWidth, sourceHeight, _blendImage->hMemDC,
			sourceX +(_imageInfo->currentFrameX * sourceWidth), sourceY + (_imageInfo->currentFrameY * sourceHeight), sourceWidth, sourceHeight, _blendFunc);
	}
	else	// ���� �̹��� �״�� ���
	{
		GdiAlphaBlend(hdc, destX, destY, sourceWidth, sourceHeight, _imageInfo->hMemDC,
			sourceX + (_imageInfo->currentFrameX * sourceWidth), sourceY + (_imageInfo->currentFrameY * sourceHeight), sourceWidth, sourceHeight, _blendFunc);
	}
}

// ���� ����
void image::loopRender(HDC hdc, const LPRECT drawArea, int offsetX, int offsetY)
{
	// ������(offset)�� �Ϲ������� ���� ������Ʈ �ȿ��� ������Ʈ ó������ �־��� ��ҳ� Ư�� ���������� ������
	// offset�� � Ư���� ������ �ణ ���̰� ���� �� �Ǵ� �� ���� ��ü�� �ǹ� (���̿� ���� ������)

	// offset ���� ������ ��� ����
	if (offsetX < 0) offsetX = _imageInfo->width + (offsetX % _imageInfo->width);
	if (offsetY < 0) offsetY = _imageInfo->height + (offsetY % _imageInfo->height);

	// �׷����� ���� ����
	RECT rcSour;
	int sourWidth;
	int sourHeight;

	// �׷����� DC ���� (ȭ��ũ��)
	RECT rcDest;

	// �׷��� �� ��ü ����
	int drawAreaX = drawArea->left;
	int drawAreaY = drawArea->top;
	int drawAreaW = drawArea->right - drawArea->left;
	int drawAreaH = drawArea->bottom - drawArea->top;

	// ���� ���� ����
	for (int y = 0; y < drawAreaH; y += sourHeight)
	{
		// �ҽ� ������ ���� ���
		rcSour.top = (y + offsetY) % _imageInfo->height;
		rcSour.bottom = _imageInfo->height;
		sourHeight = rcSour.bottom - rcSour.top;

		// �ҽ� ������ �׸��� ȭ���� �Ѿ�� ��� (ȭ������� ������ ��)
		if (y + sourHeight > drawAreaH)
		{
			// �Ѿ �׸��� ����ŭ BOTTOM�� ����
			rcSour.bottom -= (y + sourHeight) - drawAreaH;
			sourHeight = rcSour.bottom - rcSour.top;
		}

		// �׷����� ����
		rcDest.top = y + drawAreaY;
		rcDest.bottom = rcDest.top + sourHeight;

		// ���� ���� ����
		for (int x = 0; x < drawAreaW; x += sourWidth)
		{
			// �ҽ� ������ ���� ���
			rcSour.left = (x + offsetX) % _imageInfo->width;
			rcSour.right = _imageInfo->width;
			sourWidth = rcSour.right - rcSour.left;

			// �ҽ� ������ �׸��� ȭ���� �Ѿ�� ��� (ȭ������� ������ ��)
			if (x + sourWidth > drawAreaW)
			{
				// �Ѿ �׸��� ����ŭ RIGHT�� ����
				rcSour.right -= (x + sourWidth) - drawAreaW;
				sourWidth = rcSour.right - rcSour.left;
			}

			// �׷����� ����
			rcDest.left = x + drawAreaX;
			rcDest.right = rcDest.left + sourWidth;

			// ��� (�Ϲ� ���� - �̹��� �߶� ���̱�)
			render(hdc, rcDest.left, rcDest.top, rcSour.left, rcSour.top, sourWidth, sourHeight);
		}
	}
}
void image::loopAlphaRender(HDC hdc, const LPRECT drawArea, int offsetX, int offsetY, BYTE alpha)
{
	// offset ���� ������ ��� �����ϱ�
	if (offsetX < 0) offsetX = _imageInfo->width + (offsetX % _imageInfo->width);
	if (offsetY < 0) offsetY = _imageInfo->height + (offsetY % _imageInfo->height);

	// �׷����� ���� ����
	RECT rcSour;
	int sourWidth;
	int sourHeight;

	// �׷����� DC ���� (ȭ��ũ��)
	RECT rcDest;

	// �׷��� �� ��ü ����
	int drawAreaX = drawArea->left;
	int drawAreaY = drawArea->top;
	int drawAreaW = drawArea->right - drawArea->left;
	int drawAreaH = drawArea->bottom - drawArea->top;

	// ���� ���� ����
	for (int y = 0; y < drawAreaH; y += sourHeight)
	{
		// �ҽ� ������ ���� ���
		rcSour.top = (y + offsetY) % _imageInfo->height;
		rcSour.bottom = _imageInfo->height;
		sourHeight = rcSour.bottom - rcSour.top;

		// �ҽ� ������ �׸��� ȭ���� �Ѿ�� ��� (ȭ������� ������ ��)
		if (y + sourHeight > drawAreaH)
		{
			// �Ѿ �׸��� ����ŭ BOTTOM�� ����
			rcSour.bottom -= (y + sourHeight) - drawAreaH;
			sourHeight = rcSour.bottom - rcSour.top;
		}

		// �׷����� ����
		rcDest.top = y + drawAreaY;
		rcDest.bottom = rcDest.top + sourHeight;

		// ���� ���� ����
		for (int x = 0; x < drawAreaW; x += sourWidth)
		{
			// �ҽ� ������ ���� ���
			rcSour.left = (x + offsetX) % _imageInfo->width;
			rcSour.right = _imageInfo->width;
			sourWidth = rcSour.right - rcSour.left;

			// �ҽ� ������ �׸��� ȭ���� �Ѿ�� ��� (ȭ������� ������ ��)
			if (x + sourWidth > drawAreaW)
			{
				// �Ѿ �׸��� ����ŭ RIGHT�� ����
				rcSour.right -= (x + sourWidth) - drawAreaW;
				sourWidth = rcSour.right - rcSour.left;
			}

			// �׷����� ����
			rcDest.left = x + drawAreaX;
			rcDest.right = rcDest.left + sourWidth;

			// ��� (���� ���� - �̹��� �߶� ���̱�)
			alphaRender(hdc, rcDest.left, rcDest.top, rcSour.left, rcSour.top, sourWidth, sourHeight, alpha);
		}
	}
}