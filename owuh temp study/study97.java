/* Use the Java I/O routines */
import java.io.*;

/**
 * See BIO exam paper.  This program solves BIO'97 question 3 part a.
 *
 * Solution copyright (c) 1998 The British Informatics Olympiad (BIO).
 *
 * This program may be freely copied by persons or organisations
 * involved in the British Informatics Olympiad or the International
 * Olympiad in Informatics, on condition that no changes are made and
 * this notice is not altered. Distribution for profit is forbidden
 * unless permission is first obtained in writing from the BIO.
 *
 * This program is for educational purposes only and comes with no
 * warranty, implied or otherwise, as to its fitness for any purpose.
 *
 * Author:   Antony Rix
 * Internet: http://www.christs.cam.ac.uk/bio/
 * E-mail:   a.rix@lineone.net
 * S-mail:   The British Informatics Olympiad
 *           Christ's College
 *           Cambridge CB2 3BU
 *           United Kingdom
 */
class BIO97Q3A extends AppletConsoleApp {
  /**
   * Parameters A and B
   */
  int A = 1, B = 2;

  /**
   * Start the application from the command line.
   */
  public static void main(String[] args) {
	  BIO97Q3A thisApp = new BIO97Q3A();
	  thisApp.redirectStreams(System.in, System.out);
	  thisApp.run( );
	}

  /**
   * Main program of BIO97Q3A, this is run from the command line
   * by the <CODE>main()</CODE> method, or called directly by an
   * AppletConsole.
   *
   * The program reads from the stream <CODE>in</CODE> and writes
   * to the stream <CODE>out</CODE>, which are automatically assigned
   * by <CODE>main()</CODE> or by the AppletConsole class.
   */
	public void run() {
    out.println("BIO'97 Q3a:");
    out.println("Enter a/b, 0<a<b<=1000 in form a b");
    out.print(">");
    try {
  	  /* Create a StreamTokenizer to allow us to read in the two numbers
	    */
  	  StreamTokenizer sin = new StreamTokenizer( in );
	    sin.nextToken();
	    A = (int)sin.nval;
  	  sin.nextToken();
	    B = (int)sin.nval;
  	} catch (IOException e) { out.println("I/O failure"); };
  	if( (A == 0) && (B == 0) ) {
  	  A = 1; B = 20; process();
  	  A = 36; B = 612; process();
  	  A = 2; B = 15; process();
  	  A = 2; B = 37; process();
  	  A = 27; B = 441; process();
  	  A = 4; B = 109; process();
  	  A = 59; B = 211; process();
  	  A = 101; B = 103; process();
  	  A = 907; B = 911; process();
  	  A = 523; B = 547; process();
  	}
  	else {
      if( (A < 1) || (B <= A) || (B > 1000) )
        out.println("Requires 0<a<b<=1000\n.Please re-run the program.");
      else
        process();
    }
  }

  /**
   * Processes to find the solution for a given A and B using the
   * greatest common divisor method.  Will find a solution if one
   * exists with Kmax or fewer unit fractions.  Solution will be
   * (C[0] + .. C[Kmax-1])/(B * D), where D >= 1.
   */
  void process() {
    int D, BD, AD;
    int[] C = new int[4];
    int[] N = new int[4];
    int Sum;
    int BDBest = 1;
    int BDMax;
    int[] CBest = new int[4];
    int Kmax = 4;
    int DenMax = 32001;
    boolean Solved = false;
    int[] Divisors = new int[1000];
    int nDivisors;
    int i, j, k;

    out.println( A + "/" + B );
    if( B > 100 )
      BDMax = 32000;
    else
      BDMax = A * B * B;
    D = 1;
    BD = B;
    AD = A;
    while( (!Solved) || (BD <= BDMax) ) {
      // generate divisors
      nDivisors = 0;
      i = 1;
      while( (i <= AD) && (nDivisors < 1000) ) {
        if( (BD % i) == 0 ) {
          Divisors[nDivisors] = i;
          nDivisors++;
        }
        i++;
      }

      // generate permutations of divisors
      k = 1;
      N[0] = 0;
      C[0] = Divisors[N[0]];
      Sum = C[0];
      while( N[0] < nDivisors ) {
        if( Sum == AD ) {
          // solution found
          if( (k < Kmax) || ((k == Kmax) && ((BD / C[0]) < DenMax)) ) {
            Solved = true;
            Kmax = k;
            BDBest = BD;
            DenMax = BD / C[0];
            out.print( "Best solution so far: " );
            for( j = k-1; j >= 0; j-- ) {
              out.print( BD / C[j] + " " );
              CBest[j] = C[j];
            }
            out.println();
          }
        }
        if( (Sum >= AD) || (N[k-1] >= (nDivisors-1)) ) {
          // backtrack
          if( k > 1 ) {
            Sum -= (C[k-1] + C[k-2]);
            k--;
            N[k-1]++;
            C[k-1] = Divisors[N[k-1]];
            Sum += C[k-1];
          }
          else
            N[0] = nDivisors;
        }
        if( Sum < AD ) {
          // add another number to the set
          if( (k < Kmax) && (N[k-1] < (nDivisors-1)) ) {
            N[k] = N[k-1] + 1;
            C[k] = Divisors[N[k]];
            Sum += C[k];
            k++;
          } else {
            Sum -= C[k-1];
            N[k-1]++;
            C[k-1] = Divisors[N[k-1]];
            Sum += C[k-1];
          }
        }
      }

      // try next value of D
      D++;
      BD = B * D;
      AD = A * D;
    }
    if( Solved ) {
      out.print( A + "/" + B + " = 1/" + BDBest / CBest[Kmax-1]);
      for( j = Kmax-2; j >= 0; j-- )
        out.print( " + 1/" + BDBest / CBest[j] );
      out.println();
    } else
      out.println( "No solution found!" );
  }

  /**
   * Returns lowest common factor using Euclid's algorithm.
   * Requires a &lt; b.
   */
  int greatestCommonDivisor(int a, int b) {
    if (a == 0)
      return b;
    else
      return greatestCommonDivisor(b % a, a);
  }
}
