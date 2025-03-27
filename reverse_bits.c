/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 23:13:49 by oait-si-          #+#    #+#             */
/*   Updated: 2025/03/26 23:21:01 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

unsigned char revese_bit(unsigned char octet)
{
    int i = 8;
    int  c = 0;
    while(i-- >= 0 )
    {
        c = (octet >> i ) & 1;
        octet = (octet << 1) & c; 
    }
    return octet ; 
    
}

int main()
{
    char c = revese_bit('1');
    
    printf("%d", c);
    return(0);
}