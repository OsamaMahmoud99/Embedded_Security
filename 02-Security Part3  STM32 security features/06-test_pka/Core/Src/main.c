/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
/*
 * Private-Key: (1024 bit)
modulus:
    00:94:f2:d6:99:52:34:21:5e:79:a6:1e:5b:4c:e6:
    43:2e:98:2b:7b:3e:ba:08:25:2e:30:bc:05:95:c1:
    d6:27:fb:e1:bf:14:6c:80:fe:1e:12:40:c4:0e:d2:
    e0:2b:a9:ba:6b:fd:78:10:b1:f7:e2:7c:0b:06:68:
    53:a8:d8:71:94:31:ca:1e:1c:11:d4:cf:04:6a:de:
    5d:80:a0:08:2b:6e:9d:e4:bc:1b:62:c3:39:99:ea:
    d4:45:33:3a:c3:8c:c4:f3:a0:d5:d8:ff:d1:58:97:
    e4:ba:74:ee:73:8d:45:8c:dd:10:10:e9:b1:fe:d6:
    86:3d:63:2c:f7:51:67:f7:a7
publicExponent: 65537 (0x10001)
privateExponent:
    79:08:e7:f7:89:04:11:85:9a:e6:b1:4e:51:ab:df:
    35:d2:b3:aa:9f:ab:3e:09:30:82:ab:97:02:3d:94:
    0f:c3:af:8a:bd:46:fa:7f:04:e2:a2:3c:6f:2b:4e:
    bc:4c:5c:cf:7a:16:01:c3:0c:82:bf:77:9a:0a:56:
    c9:22:b1:0f:95:16:2b:aa:d1:1f:46:aa:c2:eb:00:
    f5:af:c7:cb:e0:d0:81:9b:67:58:01:3f:81:86:9e:
    b9:41:e0:ce:84:f0:55:22:10:44:df:d3:0b:52:58:
    b4:36:c9:b0:87:90:6d:bc:92:ce:19:ee:a9:bf:01:
    95:0c:e9:2c:24:aa:3b:31
prime1:
    00:c3:d5:11:48:ad:8d:fb:2e:53:79:e3:b1:0c:5a:
    9c:76:2f:d5:da:18:db:c9:86:d1:96:89:82:d3:8a:
    32:08:e4:e0:c7:b7:c9:98:96:6d:f2:16:d1:cc:60:
    2d:a6:b7:f9:73:1e:99:3e:b3:23:3f:7c:1a:65:d9:
    47:63:3d:77:ff
prime2:
    00:c2:b6:31:b4:a0:a5:e9:82:da:b4:58:81:14:2d:
    90:01:7d:47:b2:ab:90:c8:a3:ce:08:de:38:a3:95:
    96:db:64:b1:fd:1e:d0:af:61:34:41:9d:8e:84:d4:
    84:60:72:23:f7:89:92:f3:04:1b:cf:21:b0:e5:7b:
    99:98:f6:c0:59
exponent1:
    27:21:e4:9a:49:54:1d:e5:5b:f8:f7:6e:e1:b1:19:
    a2:e4:5c:2f:80:d8:2a:a5:2e:2c:8e:bd:fd:d7:97:
    b7:ff:44:8b:a4:46:3c:9f:92:c8:d5:96:86:e8:91:
    36:c7:7c:a9:6c:6b:e3:03:98:ff:8e:a5:17:c5:1b:
    66:d1:59:b1
exponent2:
    00:ab:03:cc:ea:61:c2:f7:32:78:16:b8:39:3e:d8:
    b9:c7:a5:1a:49:02:49:1b:00:4c:21:1b:d4:d1:50:
    bc:7c:1b:97:fc:c2:88:f5:d0:c1:4d:f4:2d:4d:db:
    3e:1d:5b:82:dd:92:56:9f:dc:f6:f3:d9:1a:7e:a4:
    2d:86:dd:0a:99
coefficient:
    1b:96:92:0b:3f:d4:e6:bf:37:ee:3d:3a:96:24:26:
    6f:7a:ad:19:72:a5:72:dc:81:bf:5a:a6:8f:50:03:
    34:16:ed:cc:8e:1c:4b:5a:2b:28:c2:2b:21:ab:14:
    c3:a3:af:af:92:5f:a4:a5:a0:a5:82:87:20:3d:c5:
    bd:26:89:13
writing RSA key
-----BEGIN RSA PRIVATE KEY-----
MIICXAIBAAKBgQCU8taZUjQhXnmmHltM5kMumCt7ProIJS4wvAWVwdYn++G/FGyA
/h4SQMQO0uArqbpr/XgQsffifAsGaFOo2HGUMcoeHBHUzwRq3l2AoAgrbp3kvBti
wzmZ6tRFMzrDjMTzoNXY/9FYl+S6dO5zjUWM3RAQ6bH+1oY9Yyz3UWf3pwIDAQAB
AoGAeQjn94kEEYWa5rFOUavfNdKzqp+rPgkwgquXAj2UD8Ovir1G+n8E4qI8bytO
vExcz3oWAcMMgr93mgpWySKxD5UWK6rRH0aqwusA9a/Hy+DQgZtnWAE/gYaeuUHg
zoTwVSIQRN/TC1JYtDbJsIeQbbySzhnuqb8BlQzpLCSqOzECQQDD1RFIrY37LlN5
47EMWpx2L9XaGNvJhtGWiYLTijII5ODHt8mYlm3yFtHMYC2mt/lzHpk+syM/fBpl
2UdjPXf/AkEAwrYxtKCl6YLatFiBFC2QAX1HsquQyKPOCN44o5WW22Sx/R7Qr2E0
QZ2OhNSEYHIj94mS8wQbzyGw5XuZmPbAWQJAJyHkmklUHeVb+Pdu4bEZouRcL4DY
KqUuLI69/deXt/9Ei6RGPJ+SyNWWhuiRNsd8qWxr4wOY/46lF8UbZtFZsQJBAKsD
zOphwvcyeBa4OT7YucelGkkCSRsATCEb1NFQvHwbl/zCiPXQwU30LU3bPh1bgt2S
Vp/c9vPZGn6kLYbdCpkCQBuWkgs/1Oa/N+49OpYkJm96rRlypXLcgb9apo9QAzQW
7cyOHEtaKyjCKyGrFMOjr6+SX6SloKWChyA9xb0miRM=
-----END RSA PRIVATE KEY-----

G:\OSAMAA\Embedded System\29-Automotive_CyberSecurity\06-STM32_Security\03-Security Part3  STM32 security features\OpenSSL_tools>openssl.exe rsa -in MyPrivKey.pem -pubout -out MyPubKey.pem
writing RSA key

G:\OSAMAA\Embedded System\29-Automotive_CyberSecurity\06-STM32_Security\03-Security Part3  STM32 security features\OpenSSL_tools>hexdump.exe plaintext.bin
000000  00 01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f
000010  00 01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f
000020  00 01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f
000030  00 01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f
000040  00 01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f
000050  00 01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f
000060  00 01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f
000070  00 01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f

G:\OSAMAA\Embedded System\29-Automotive_CyberSecurity\06-STM32_Security\03-Security Part3  STM32 security features\OpenSSL_tools>openssl.exe rsautl -raw -pubin -inkey MyPubKey.pem -encrypt -in plaintext.bin -out plaintext_encrypted.bin

G:\OSAMAA\Embedded System\29-Automotive_CyberSecurity\06-STM32_Security\03-Security Part3  STM32 security features\OpenSSL_tools>hexdump.exe plaintext_encrypted.bin
000000  25 bb 43 ea 10 20 42 af 56 ab 06 67 03 fe 93 2a
000010  0a fd ca 53 05 14 aa 23 46 43 2c 2f 38 41 e9 77
000020  13 52 63 eb 42 36 23 55 7c ad 20 4f cc c6 28 06
000030  a2 ef ab 2f 97 2f 46 32 72 a5 21 3a 8b 44 15 22
000040  e9 02 d2 4a 31 dc 60 fd 57 10 5c 00 da 7d cc d9
000050  6b e0 f1 10 d8 c9 72 bf 7b fb 63 8b c6 6f 4d c7
000060  45 29 fe be 20 14 2f 32 e4 bb ef 19 66 5a df 95
000070  68 a7 29 0e 0a 02 9e 03 40 ad b2 9f d8 1a 81 8a
 */
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

PKA_HandleTypeDef hpka;

/* USER CODE BEGIN PV */

uint8_t modulus[]= {
	0x00,0x94,0xf2,0xd6,0x99,0x52,0x34,0x21,0x5e,0x79,
	0xa6,0x1e,0x5b,0x4c,0xe6,0x43,0x2e,0x98,0x2b,0x7b,
	0x3e,0xba,0x08,0x25,0x2e,0x30,0xbc,0x05,0x95,0xc1,
	0xd6,0x27,0xfb,0xe1,0xbf,0x14,0x6c,0x80,0xfe,0x1e,
	0x12,0x40,0xc4,0x0e,0xd2,0xe0,0x2b,0xa9,0xba,0x6b,
	0xfd,0x78,0x10,0xb1,0xf7,0xe2,0x7c,0x0b,0x06,0x68,
	0x53,0xa8,0xd8,0x71,0x94,0x31,0xca,0x1e,0x1c,0x11,
	0xd4,0xcf,0x04,0x6a,0xde,0x5d,0x80,0xa0,0x08,0x2b,
	0x6e,0x9d,0xe4,0xbc,0x1b,0x62,0xc3,0x39,0x99,0xea,
	0xd4,0x45,0x33,0x3a,0xc3,0x8c,0xc4,0xf3,0xa0,0xd5,
	0xd8,0xff,0xd1,0x58,0x97,0xe4,0xba,0x74,0xee,0x73,
	0x8d,0x45,0x8c,0xdd,0x10,0x10,0xe9,0xb1,0xfe,0xd6,
	0x86,0x3d,0x63,0x2c,0xf7,0x51,0x67,0xf7,0xa7
};
uint8_t publicExponent[]={0x00,0x01,0x00,0x01};

uint8_t privateExponent[]={
	0x79,0x08,0xe7,0xf7,0x89,0x04,0x11,0x85,0x9a,0xe6,
	0xb1,0x4e,0x51,0xab,0xdf,0x35,0xd2,0xb3,0xaa,0x9f,
	0xab,0x3e,0x09,0x30,0x82,0xab,0x97,0x02,0x3d,0x94,
	0x0f,0xc3,0xaf,0x8a,0xbd,0x46,0xfa,0x7f,0x04,0xe2,
	0xa2,0x3c,0x6f,0x2b,0x4e,0xbc,0x4c,0x5c,0xcf,0x7a,
	0x16,0x01,0xc3,0x0c,0x82,0xbf,0x77,0x9a,0x0a,0x56,
	0xc9,0x22,0xb1,0x0f,0x95,0x16,0x2b,0xaa,0xd1,0x1f,
	0x46,0xaa,0xc2,0xeb,0x00,0xf5,0xaf,0xc7,0xcb,0xe0,
	0xd0,0x81,0x9b,0x67,0x58,0x01,0x3f,0x81,0x86,0x9e,
	0xb9,0x41,0xe0,0xce,0x84,0xf0,0x55,0x22,0x10,0x44,
	0xdf,0xd3,0x0b,0x52,0x58,0xb4,0x36,0xc9,0xb0,0x87,
	0x90,0x6d,0xbc,0x92,0xce,0x19,0xee,0xa9,0xbf,0x01,
	0x95,0x0c,0xe9,0x2c,0x24,0xaa,0x3b,0x31
};

uint8_t plaintext[128]={
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f,
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f,
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f,
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f,
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f,
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f,
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f,
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f
};

uint8_t encrypted_data[128];
uint8_t decrypted_data[128];
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void PeriphCommonClock_Config(void);
static void MX_PKA_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */
	PKA_ModExpInTypeDef in;

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* Configure the peripherals common clocks */
  PeriphCommonClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_PKA_Init();
  /* USER CODE BEGIN 2 */
  in.expSize = sizeof(publicExponent);
  in.OpSize = sizeof(modulus);
  in.pExp = publicExponent;
  in.pMod = modulus;
  in.pOp1 = plaintext;
  if (HAL_PKA_ModExp(&hpka, &in, 1000) != HAL_OK)
  {
	  Error_Handler();
  }

  HAL_PKA_ModExp_GetResult(&hpka, encrypted_data);

  in.expSize = sizeof(privateExponent);
  in.OpSize = sizeof(modulus);
  in.pExp = privateExponent;
  in.pMod = modulus;
  in.pOp1 = plaintext;
  if (HAL_PKA_ModExp(&hpka, &in, 5000) != HAL_OK)
  {
	  Error_Handler();
  }

  HAL_PKA_ModExp_GetResult(&hpka, decrypted_data);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.MSICalibrationValue = RCC_MSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure the SYSCLKSource, HCLK, PCLK1 and PCLK2 clocks dividers
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK4|RCC_CLOCKTYPE_HCLK2
                              |RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_MSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.AHBCLK2Divider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.AHBCLK4Divider = RCC_SYSCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief Peripherals Common Clock Configuration
  * @retval None
  */
void PeriphCommonClock_Config(void)
{
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};

  /** Initializes the peripherals clock
  */
  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_SMPS;
  PeriphClkInitStruct.SmpsClockSelection = RCC_SMPSCLKSOURCE_HSI;
  PeriphClkInitStruct.SmpsDivSelection = RCC_SMPSCLKDIV_RANGE1;

  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN Smps */

  /* USER CODE END Smps */
}

/**
  * @brief PKA Initialization Function
  * @param None
  * @retval None
  */
static void MX_PKA_Init(void)
{

  /* USER CODE BEGIN PKA_Init 0 */

  /* USER CODE END PKA_Init 0 */

  /* USER CODE BEGIN PKA_Init 1 */

  /* USER CODE END PKA_Init 1 */
  hpka.Instance = PKA;
  if (HAL_PKA_Init(&hpka) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN PKA_Init 2 */

  /* USER CODE END PKA_Init 2 */

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
